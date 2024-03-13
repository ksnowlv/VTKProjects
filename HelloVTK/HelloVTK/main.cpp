//
//  main.cpp
//  HelloVTK
//
//  Created by ksnowlv on 2024/3/12.
//

#include <iostream>

#include <vtkSmartPointer.h>
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>

int main() {
    // 创建一个圆柱体数据源
    vtkSmartPointer<vtkCylinderSource> cylinderSource = vtkSmartPointer<vtkCylinderSource>::New();
    cylinderSource->SetHeight(6.0);
    cylinderSource->SetRadius(3.0);
    cylinderSource->SetResolution(8);

    // 创建一个映射器
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(cylinderSource->GetOutputPort());

    // 创建一个Actor
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    // 设置颜色
    actor->GetProperty()->SetColor(0.6, 0.0, 0.6);

    // 创建渲染器和渲染窗口
    vtkSmartPointer<vtkRenderer> render = vtkSmartPointer<vtkRenderer>::New();
    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(render);
    
    // 将演员添加到渲染器中
    render->AddActor(actor);
    render->SetBackground(0.1, 1.0, 1.0);
    

    // 创建交互器
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow);


    // 设置渲染窗口的大小，并开始渲染
    renderWindow->Render();
    renderWindow->SetSize(1200, 800);
    renderWindow->SetPosition(100, 300);
    renderWindow->SetWindowName("My VTK Window");

    // 运行交互器
    renderWindowInteractor->Start();

    return 0;
}


