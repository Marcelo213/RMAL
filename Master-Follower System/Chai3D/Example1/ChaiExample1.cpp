using namespace chai3d;
// create a new world.
world = new cWorld();

// set the background color of the environment to black
world->m_backgroundColor.setBlack();






// create a camera
camera = new cCamera(world);

// add the camera to the world
world->addChild(camera);

// position and orient the camera
camera->set(cVector3d(3.0, 0.0, 0.0),    // camera position (eye)
            cVector3d(0.0, 0.0, 0.0),    // lookat position (target)
            cVector3d(0.0, 0.0, 1.0));   // direction of the (up) vector
            
// set the near and far clipping planes of the camera
// anything in front/behind these clipping planes will not be rendered
camera->setClippingPlanes(0.01, 10.0);






// create a light source
light = new cDirectionalLight(world);

// add light to world
world->addChild(light);

// enable light source
light->setEnabled(true);                   

// define the direction
light->setDir(-1.0, -1.0, -1.0); 