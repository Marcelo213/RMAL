#include <environment.h>


Environment::Environment () {

    mp_Ren = vtkSmartPointer<vtkRenderer>::New();
	mp_RenWin = vtkSmartPointer<vtkRenderWindow>::New();
	mp_RenWin->AddRenderer(mp_Ren);

    // General settings
    mp_Ren->SetBackground(1,1,1);
	mp_RenWin->SetWindowName("Taha Catheter Simulation");

	// Initialize the scene (light, floor coordinate frames etc)
	vtkSmartPointer<vtkOpenGLLight> sceneLight = vtkSmartPointer<vtkOpenGLLight>::New();
    sceneLight->SetDirectionAngle(45,0);
    sceneLight->SetDiffuseColor(0.8,0.8,0.9);
    sceneLight->SetSpecularColor(0.98,0.98,0.98);
    sceneLight->SetIntensity(1);
    mp_Ren->AddLight(sceneLight);
    
	//Camera
    mp_Ren->GetActiveCamera()->SetPosition(0,0,150);
    mp_Ren->GetActiveCamera()->SetFocalPoint(0.05,0,0.05);  
    mp_Ren->GetActiveCamera()->SetViewUp(0,0,-1);     
    //std::array<unsigned char, 3> blk{{0, 0, 0}};
    //mp_colors->SetColor("Black", blk.data());

}