#include "../include/presenter.hpp"

Presenter::Presenter():
    m_systemState(SystemState()),
    m_view(View()),
    m_transformBuffer(vector<glm::mat4>{}),
    m_indexBuffer(vector<vector<unsigned int>>{}),
    m_colourBuffer(vector<glm::vec3>{})
{}

Presenter::~Presenter(){

}

//those visitors that get the information we need in our buffers
void Presenter::visitDrawPoint(Component& pointMass){

    m_transformBuffer.push_back(glm::scale(glm::mat4(1.0f), glm::vec3(0.5f, 0.5f, 1.0f)));
    m_indexBuffer.push_back(m_view.getCircle());
    m_colourBuffer.push_back(glm::vec3(1.0f, 1.0f, 1.0f));
}
void Presenter::visitDrawBeam(Component& beam){

    m_transformBuffer.push_back(glm::mat4(1.0f));
    m_indexBuffer.push_back(m_view.getSquare());
    m_colourBuffer.push_back(glm::vec3(0.0f, 0.0f, 0.0f));
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
void Presenter::drawView(glm::vec3 viewportScale){
    m_view.startFrame();

    //fill out presenter buffers before rendering 
    for(unsigned int i = 0; i < m_systemState.getComponents().size(); i++){
        Component* c = m_systemState.getComponents().at(i);
        
        (*c).acceptDraw(*this); //update our current buffers in a specific way (visitor gets underlying type)

        assert(m_transformBuffer.size() == m_colourBuffer.size()); //one transformation for every colour
        assert(m_transformBuffer.size() == m_indexBuffer.size()); //one transformation for every shape
        //=> one colour for every shape
    }

    //draw all the shapes to screen for every component
    for(unsigned int j = 0; j < m_transformBuffer.size(); j++){
        glm::mat4 transViewportScale = glm::scale(m_transformBuffer.at(j), viewportScale);
        m_view.drawShape(
            m_indexBuffer.at(j), //the component sub/shape
            transViewportScale, //transformation for the sub/shape
            glm::vec4(m_colourBuffer.at(j), 1.0f) //colour for the sub/shape
        ); 
    }

    clearBuffers();
}