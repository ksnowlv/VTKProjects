//
//  ShapRender.cpp
//  HelloVTK
//
//  Created by ksnowlv on 2024/3/13.
//

#include "ShapRender.hpp"

#include <vtkSmartPointer.h>
#include <vtkCylinderSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>

//cubeRender
#include <vtkCubeSource.h>
#include <vtkJPEGReader.h>
#include <vtkTexture.h>
#include <vtkPNGReader.h>

//lineRender
#include <vtkLineSource.h>
#include <vtkPolyData.h>
#include <vtkPointData.h>

//
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkUnsignedCharArray.h>
#include <vtkCellData.h>

//vtkPolygon
#include <vtkPolygon.h>
#include <vtkNamedColors.h>

//
#include <vtkConeSource.h>

//
#include <vtkSphereSource.h>

ShapeRender::ShapeRender() {
    
}

ShapeRender::~ShapeRender() {
    
}

void ShapeRender::CylinderRender() {
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
    
    VTKRender(actor);
    
}

const std::string jpgImagePath = "Resource/flutter.jpg";
const std::string pngimagePath = "Resource/flutter.png";


void ShapeRender::CubeRender() {
    // 创建正方体
    vtkSmartPointer<vtkCubeSource> cubeSource = vtkSmartPointer<vtkCubeSource>::New();
    
    // 创建正方体映射
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(cubeSource->GetOutputPort());
    
    // 创建jpg图片纹理
    vtkSmartPointer<vtkJPEGReader> jpegReader = vtkSmartPointer<vtkJPEGReader>::New();
    jpegReader->SetFileName(jpgImagePath.c_str());
    
    // 创建png图片纹理
    vtkSmartPointer<vtkPNGReader> pngReader = vtkSmartPointer<vtkPNGReader>::New();
    pngReader->SetFileName(pngimagePath.c_str());
    
    vtkSmartPointer<vtkTexture> texture = vtkSmartPointer<vtkTexture>::New();
    texture->SetInputConnection(jpegReader->GetOutputPort());
    
    // 创建包含纹理映射的角色
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->SetTexture(texture);
    
    VTKRender(actor);
}

void ShapeRender::LineRender() {
    
    vtkSmartPointer<vtkLineSource> lineSource = vtkSmartPointer<vtkLineSource>::New();
    //起点和终点的范围大约在 (0, 0, 0) 到 (1, 1, 1) 之间
    lineSource->SetPoint1(0.0, 0.0, 0.0);  // 设置起点坐标
    lineSource->SetPoint2(0.0, 0.5, 0.0);  // 设置终点坐标
    
    
    // 创建一个映射
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(lineSource->GetOutputPort());
    
    // 创建一个角色
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    // 设置直线的宽度
    actor->GetProperty()->SetLineWidth(3);
    // 设置直线的颜色
    actor->GetProperty()->SetColor(1.0, 1.0, 1.0);
    
    
    VTKRender(actor);
}

void ShapeRender::PolyLineRender() {
    // 创建所有折线的点
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    //用来表示点的X、Y、Z坐标。具体来说，参数范围可以是任意的浮点数
    points->InsertNextPoint(0, 0, 0);  // 起点
    points->InsertNextPoint(1, 1, 1);  // 段1终点
    points->InsertNextPoint(2, 1, 1);  // 段2终点
    points->InsertNextPoint(3, 1, 0);  // 段3终点
    
    // 创建折线的单元
    vtkSmartPointer<vtkCellArray> lines = vtkSmartPointer<vtkCellArray>::New();
    vtkIdType line[2];
    line[0] = 0; line[1] = 1;
    lines->InsertNextCell(2, line);  // 线段1
    line[0] = 1; line[1] = 2;
    lines->InsertNextCell(2, line);  // 线段2
    line[0] = 2; line[1] = 3;
    lines->InsertNextCell(2, line);  // 线段3
    
    // 创建颜色数组
    vtkSmartPointer<vtkUnsignedCharArray> colors = vtkSmartPointer<vtkUnsignedCharArray>::New();
    colors->SetNumberOfComponents(3);
    colors->SetNumberOfTuples(3);
    
    // 设置每段直线的颜色
    unsigned char colorSegment1[3] = {255, 0, 0};  // 红色
    unsigned char colorSegment2[3] = {0, 255, 0};  // 绿色
    unsigned char colorSegment3[3] = {0, 0, 255};  // 蓝色
    colors->SetTypedTuple(0, colorSegment1);
    colors->SetTypedTuple(1, colorSegment2);
    colors->SetTypedTuple(2, colorSegment3);
    
    // 创建PolyData并将点和线数据设置进去
    vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
    polyData->SetPoints(points);
    polyData->SetLines(lines);
    polyData->GetCellData()->SetScalars(colors);
    
    // 创建Mapper
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputData(polyData);
    
    // 创建Actor
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->SetLineWidth(3);
    
    VTKRender(actor);
}

void ShapeRender::TriangleRender() {
    // 创建三角形的点
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    points->InsertNextPoint(0, 0, 0);  // 第一个点
    points->InsertNextPoint(1, 0, 0);  // 第二个点
    points->InsertNextPoint(0.5, 1, 0);  // 第三个点
    
    // 创建三角形的单元
    vtkSmartPointer<vtkCellArray> polygons = vtkSmartPointer<vtkCellArray>::New();
    vtkSmartPointer<vtkPolygon> polygon = vtkSmartPointer<vtkPolygon>::New();
    polygon->GetPointIds()->SetNumberOfIds(3);  // 三个顶点
    polygon->GetPointIds()->SetId(0, 0);
    polygon->GetPointIds()->SetId(1, 1);
    polygon->GetPointIds()->SetId(2, 2);
    polygons->InsertNextCell(polygon);
    
    // 创建三角形的颜色
    vtkSmartPointer<vtkUnsignedCharArray> colors = vtkSmartPointer<vtkUnsignedCharArray>::New();
    colors->SetNumberOfComponents(3);
    colors->SetNumberOfTuples(1);
    unsigned char color[3] = {255, 0, 0};
    colors->SetTypedTuple(0, color);
    
    // 创建PolyData并将点、单元和颜色数据设置进去
    vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
    polyData->SetPoints(points);
    polyData->SetPolys(polygons);
    polyData->GetCellData()->SetScalars(colors);
    
    // 创建Mapper
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputData(polyData);
    
    // 创建Actor
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    
    // 设置颜色和阴影,会覆盖上面设置 polyData->GetCellData()->SetScalars(colors);设置的颜色；
    //如果要观察上面设置颜色的效果，可以把下面代码注释掉
    actor->GetProperty()->SetColor(1.0, 0.0, 1.0);  // 设置填充颜色为品红色
    actor->GetProperty()->SetAmbient(0.3);  // 环境光系数
    actor->GetProperty()->SetDiffuse(0.0);  // 散射光系数
    actor->GetProperty()->SetSpecular(1.0);  // 镜面反射
    
    VTKRender(actor);
}

void ShapeRender::SquareRender() {
    // 创建正方形的顶点坐标
    vtkSmartPointer<vtkPoints> points = vtkSmartPointer<vtkPoints>::New();
    points->InsertNextPoint(0, 0, 0);
    points->InsertNextPoint(1, 0, 0);
    points->InsertNextPoint(1, 1, 0);
    points->InsertNextPoint(0, 1, 0);
    
    // 创建单元，并添加顶点索引
    vtkSmartPointer<vtkCellArray> polys = vtkSmartPointer<vtkCellArray>::New();
    constexpr int KPointNum = 4;
    vtkIdType quad[KPointNum] = {0, 1, 2, 3};
    polys->InsertNextCell(4, quad);
    
    // 创建 PolyData，并设置顶点与单元
    vtkSmartPointer<vtkPolyData> square = vtkSmartPointer<vtkPolyData>::New();
    square->SetPoints(points);
    square->SetPolys(polys);
    
    // 创建Mapper
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputData(square);
    
    // 创建Actor
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->SetColor(1.0, 0.0, 1.0);  // 设置颜色为紫色
    
    VTKRender(actor);
}

void ShapeRender::ConeRender() {
    // 创建圆锥对象
    vtkSmartPointer<vtkConeSource> cone = vtkSmartPointer<vtkConeSource>::New();
    //设置圆锥面，越大越接近圆锥面；可以对比下，设置10与100的区别
    cone->SetResolution(100);
    
    // 创建 Mapper
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(cone->GetOutputPort());
    
    // 创建 Actor
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->SetColor(1.0, 0.0, 1.0);  // 设置颜色为紫色
    VTKRender(actor);
}

void ShapeRender::SphereRender() {
    // 创建球体对象
    vtkSmartPointer<vtkSphereSource> sphere = vtkSmartPointer<vtkSphereSource>::New();
    sphere->SetThetaResolution(40);
    sphere->SetPhiResolution(40);
    
    // 创建 Mapper
    vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapper->SetInputConnection(sphere->GetOutputPort());

    // 创建 Actor
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    actor->SetMapper(mapper);
    actor->GetProperty()->SetColor(1.0, 0.0, 1.0);  // 设置颜色为紫色
    
    VTKRender(actor);
    
}


void ShapeRender::VTKRender(vtkProp* actor) {
    // 创建渲染器
    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(actor);
    renderer->SetBackground(0.6, 0.2, 0.4);
    
    // 创建渲染窗口
    vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer(renderer);
    renderWindow->SetSize(1200, 800);
    renderWindow->SetPosition(100, 300);
    // 开始渲染
    renderWindow->Render();
    //必须放在Render之后，不然，可能显示不出来窗口标题
    renderWindow->SetWindowName("My VTK Window");
    
    
    // 创建交互器
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow);
    
    // 开始交互
    renderWindowInteractor->Start();
}


