//
//  Logger.cpp
//  HelloVTK
//
//  Created by ksnowlv on 2024/3/14.
//

#include "Logger.hpp"

#include <vtkSmartPointer.h>
#include <vtkOutputWindow.h>

Logger* Logger::m_instance = nullptr;

Logger::Logger() {
    
    vtkSmartPointer<vtkOutputWindow> outputWindow = vtkSmartPointer<vtkOutputWindow>::New();
    vtkOutputWindow::SetInstance(outputWindow);
}

Logger::Logger(const Logger&) {
    
}

Logger& Logger::operator=(const Logger&) {
    return *m_instance;
}

Logger::~Logger() {
    
}

void Logger::LogDebugMessage(const char* message) {
    //vtkDebugMacro(<<message);
    vtkWarningMacro(<< "Debug: " << message);
}

void Logger::LogWarningMessage(const char* message) {
    vtkWarningMacro(<<message);
}

void Logger::LogErrorMessage(const char* message) {
    vtkErrorMacro(<<message);
}

void Logger::LogFatalMessage(const char* message) {
    vtkWarningMacro(<<message);
}
