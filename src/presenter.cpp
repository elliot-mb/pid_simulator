#include "../include/presenter.hpp"

Presenter::Presenter():
    m_systemState(SystemState()),
    m_view(View()),
    m_transformBuffer(vector<glm::mat4>{}),
    m_indexBuffer(vector<vector<unsigned int>>{}),
    m_colourBuffer(vector<glm::vec3>{}),
    m_viewportTransform(glm::mat4(1.0f))
{}

Presenter::~Presenter(){

}

//those visitors that get the information we need in our buffers
void Presenter::visit(PointMass& pointMass){

    glm::mat4 trans = glm::translate(m_viewportTransform, glm::vec3(pointMass.getPos(), 0.0f));
    trans = glm::scale(trans, glm::vec3(0.1f, 0.1f, 1.0f));

    m_transformBuffer.push_back(trans);
    m_indexBuffer.push_back(m_view.getCircle());
    m_colourBuffer.push_back(glm::vec3(1.0f, 0.5f, 0.5f));
}
void Presenter::visit(Beam& beam){

    Beam* b = dynamic_cast<Beam*>(&beam);
    vec2 direction = b->getPosA() - b->getPosB();
    float distance = glm::length(direction);

    float theta;
    if(direction.x == 0.0f){
        theta = glm::half_pi<float>();
    }else{
        theta = glm::atan((float) direction.y / direction.x);
    }

    glm::mat4 trans = m_viewportTransform;
    trans = glm::translate(trans, glm::vec3(beam.getPos(), 1.0f));
    trans = glm::rotate(trans, theta, glm::vec3(0.0f, 0.0f, 1.0f));
    trans = glm::scale(trans, glm::vec3(distance, 0.1f, 1.0f));

    m_transformBuffer.push_back(trans);
    m_indexBuffer.push_back(m_view.getSquare());
    m_colourBuffer.push_back(glm::vec3(0.5f, 0.5f, 0.5f));
}

SystemState& Presenter::getSystemState(){ //not const, we want to perform actions on this once returned
    return m_systemState; 
}

View& Presenter::getView(){
    return m_view;
}

void Presenter::clearBuffers(){
    m_transformBuffer.clear();
    m_indexBuffer.clear();
    m_colourBuffer.clear();
}

//loop over all shapes in the scene, get their transformations, and draw them to screen using view
void Presenter::drawView(){

    // .: all interactions with model :.
    //fill out presenter buffers before rendering 
    for(unsigned int i = 0; i < m_systemState.getComponents().size(); i++){
        Component* c = m_systemState.getComponents().at(i);
        
        (*c).accept(*this); //update our current buffers in a specific way (visitor gets underlying type)

        assert(m_transformBuffer.size() == m_colourBuffer.size()); //one transformation for every colour
        assert(m_transformBuffer.size() == m_indexBuffer.size()); //one transformation for every shape
        //=> one colour for every shape
    }


    // .: all interactions with view :. 
    m_view.startFrame();

    //draw all the shapes to screen for every component
    for(unsigned int j = 0; j < m_transformBuffer.size(); j++){
        m_view.drawShape(
            m_indexBuffer.at(j), //the component sub/shape
            m_transformBuffer.at(j), //transformation for the sub/shape
            glm::vec4(m_colourBuffer.at(j), 1.0f) //colour for the sub/shape
        ); 
    }

    clearBuffers();
}

void Presenter::setViewportTransform(float viewportRatio){
    m_viewportTransform = glm::scale(glm::mat4(1.0f), glm::vec3(viewportRatio, viewportRatio, 1.0f));
}