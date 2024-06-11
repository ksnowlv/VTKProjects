//
//  main.cpp
//  HelloVTK
//
//  Created by ksnowlv on 2024/3/12.
//

#include <iostream>
#include "ShapRender.hpp"


#include "Logger.hpp"


int main() {
    
    Logger* logger = Logger::GetInstance();
    logger->LogDebugMessage("这是一个debug级别的日志消息。");
    logger->LogWarningMessage("这是一个warn级别的日志消息。");
    logger->LogErrorMessage("这是一个error级别的日志消息.");
    logger->LogFatalMessage("这是一个fatal级别的日志消息.");
    cout<<"---Macro USE----"<<endl;
    vtkGenericWarningMacro("Warning message");
    vtkErrorWithObjectMacro(logger, "error message");
    vtkDebugWithObjectMacro(logger, "debug message");
    vtkWarningWithObjectMacro(logger, "warning message");
    

    std::unique_ptr<ShapeRender> render(std::make_unique<ShapeRender>());

    //render->CylinderRender();
    //render->CubeRender();
    //render->LineRender();
    //render->PolyLineRender();
    //render->TriangleRender();
   // render->SquareRender();
    //render->ConeRender();
    //render->SphereRender();
    //render->TextRender();
    //render->ButtonRender();
    render->EarthRender();
    

    
    return EXIT_SUCCESS;
}


