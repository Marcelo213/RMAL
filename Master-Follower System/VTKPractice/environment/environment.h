#include <vtkSmartPointer.h>

class Environment{
    
    private:
        vtkSmartPointer<vtkObject> MyObject = vtkSmartPointer<vtkObject>::New();



        vtkSmartPointer<vtkRenderer> mp_Ren;
		vtkSmartPointer<vtkRenderWindow> mp_RenWin;
        //std::vector<vtkSmartPointer<vtkActor>> mp_curves;
        std::vector<vtkSmartPointer<vtkActor>> m_curveActors;
        std::vector<vtkSmartPointer<vtkActor>> m_sphereActors;
        std::vector<vtkSmartPointer<vtkActor>> m_frameActors;
        std::vector<vtkSmartPointer<vtkActor>> m_cathActors;
        std::vector<vtkSmartPointer<vtkActor>> m_aortaActors;


    public:
        Environment();
        ~Environment();
}: