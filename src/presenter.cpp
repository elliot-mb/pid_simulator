#include "../include/presenter.hpp"

Presenter::Presenter():
    m_systemState(SystemState())
{}

//those visitors that will get our transformation matries for the resp. concrete objects
vector<glm::mat4>& Presenter::visitDraw(PointMass& pointMass){
    vector<glm::mat4> res; 
    res.push_back(glm::mat4(1.0f));
    return res;
}
vector<glm::mat4>& Presenter::visitDraw(Beam& beam){
    vector<glm::mat4> res; 
    res.push_back(glm::mat4(1.0f));
    return res;
}

//those visitors that will get our vertex sets/shapes for the resp. concrete objects
const vector<vector<unsigned int>>& Presenter::visitIndices(PointMass& pointMass){
    vector<vector<unsigned int>> res; 
    res.push_back(m_view.getCircle());
    return res;
}
const vector<vector<unsigned int>>& Presenter::visitIndices(Beam& beam){
    vector<vector<unsigned int>> res; 
    res.push_back(m_view.getSquare());
    return res;
}

SystemState& Presenter::getSystemState(){ //not const, we want to perform actions on this once returned
    return m_systemState; 
}

//loop over all shapes in the scene, get their transformations, and draw them to screen using view
void Presenter::drawView(){
    vector<Component> components = m_systemState.getComponents();

    for(unsigned int i = 0; i < components.size(); i++){
        Component& c = components[i];
        //as a visitor we gather data on our underlying components
        vector<glm::mat4> transforms = c.acceptDraw(*this);
        vector<vector<unsigned int>> shapes = c.acceptIndices(*this);

        assert(transforms.size() == shapes.size()); //1:1 transform:shape

        for(unsigned int j = 0; j < transforms.size(); j++){
            m_view.drawShape(shapes[j], transforms[j], glm::vec4(1.0f, 0.0f, 1.0f, 1.0f)); 
        }
    }
}