//
//  Logger.hpp
//  HelloVTK
//
//  Created by ksnowlv on 2024/3/14.
//

#ifndef Logger_hpp
#define Logger_hpp

#include <stdio.h>

#include <vtkObject.h>
class vtkLogger;

class Logger: public vtkObject {
    
public:
    // 获取单例实例的方法
    static Logger* GetInstance()
    {
        if (!m_instance)
        {
            m_instance = new Logger();
        }
        return m_instance;
    }

    
    ~Logger();
    
public:

    // 输出debug级别的日志消息
    void LogDebugMessage(const char* message);

       // 输出warn级别的日志消息
    void LogWarningMessage(const char* message);

       // 输出error级别的日志消息
    void LogErrorMessage(const char* message);

       // 输出fatal级别的日志消息
    void LogFatalMessage(const char* message);
    
private:
    // 私有化构造函数和拷贝构造函数
    Logger();
    Logger(const Logger&);
    Logger& operator=(const Logger&);

private:
    static Logger* m_instance;

};

#endif /* Logger_hpp */
