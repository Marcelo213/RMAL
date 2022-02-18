/*=========================================================================

  Program:   Visualization Toolkit
  Module:    Cylinder.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// This file is edited from the example into our purpose for the environment

//
// This simple example shows how to do basic rendering and pipeline
// creation using C++.
//
#include "vtkCylinderSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkProperty.h"
#include "vtkCamera.h"


// Added from Tut 1
#include "vtkNamedColors.h"



#include <vtkSTLReader.h>



int main()
{

  //
  // Next we create an instance of vtkNamedColors and we will use
  // this to select colors for the object and background.
  //
  vtkNew<vtkNamedColors> colors;



  // This creates a polygonal cylinder model with sixteen circumferential facets.
  //
  vtkCylinderSource *cylinder = vtkCylinderSource::New();
  cylinder->SetHeight(3);
  cylinder->SetRadius(2);
  cylinder->SetResolution(16);
  cylinder->CappingOff();

  // The mapper is responsible for pushing the geometry into the graphics
  // library. It may also do color mapping, if scalars or other attributes
  // are defined.
  //
  vtkPolyDataMapper *cylinderMapper = vtkPolyDataMapper::New();
  cylinderMapper->SetInputConnection(cylinder->GetOutputPort());

  // The actor is a grouping mechanism: besides the geometry (mapper), it
  // also has a property, transformation matrix, and/or texture map.
  // Here we set its color and rotate it -22.5 degrees.
  vtkActor *cylinderActor = vtkActor::New();
  cylinderActor->SetMapper(cylinderMapper);
  cylinderActor->GetProperty()->SetColor(1.0000, 0.3882, 0.2784);
  //cylinderActor->RotateX(30.0);
  //cylinderActor->RotateY(-45.0);


  // This is to create the second cylinder
  vtkActor *cylinderActor2 = vtkActor::New();
  cylinderActor2->SetMapper(cylinderMapper);
  cylinderActor2->GetProperty()->SetColor(1.0000, 0.3882, 0.2784);
  //cylinderActor2->RotateX(30.0);
  cylinderActor2->RotateZ(-30.0);
  cylinderActor2->SetPosition(0, 2, 0);
  cylinderActor2->GetProperty()->SetColor(0.2, 0.63, 0.79);



  // Create the graphics structure. The renderer renders into the
  // render window. The render window interactor captures mouse events
  // and will perform appropriate camera or actor manipulation
  // depending on the nature of the events.
  //
  vtkRenderer *ren1 = vtkRenderer::New();
  vtkRenderWindow *renWin = vtkRenderWindow::New();
  renWin->AddRenderer(ren1);
  vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
  iren->SetRenderWindow(renWin);

  // Add the actors to the renderer, set the background and size
  //
  ren1->AddActor(cylinderActor);
  ren1->AddActor(cylinderActor2);
  ren1->SetBackground(0.1, 0.2, 0.4);
  renWin->SetSize(400, 400);
  renWin->SetWindowName("Object 1");

  // We'll zoom in a little by accessing the camera and invoking a "Zoom"
  // method on it.
  ren1->ResetCamera();
  ren1->GetActiveCamera()->Zoom(1.5);
  renWin->Render();

  // This starts the event loop and as a side effect causes an initial render.
  iren->Start();

  // Exiting from here, we have to delete all the instances that
  // have been created.
  cylinder->Delete();
  cylinderMapper->Delete();
  cylinderActor->Delete();
  ren1->Delete();
  renWin->Delete();
  iren->Delete();

  return 0;
}




