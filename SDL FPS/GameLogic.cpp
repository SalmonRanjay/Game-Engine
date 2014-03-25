#include "GameLogic.h"

GameLogic::GameLogic()
{
	createWindow();
	//cam.setLocation(vector3d(10,10,10));
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,640/480.0,1,500.0);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	//player1 = new Player(collisionsphere(vector3d(0.0,0.0,0.0),3.0),0.2,0.2);

};

void GameLogic::createWindow()
{
	SDL_Init(SDL_INIT_EVERYTHING);//initializing the window
	SDL_Surface* screen;
	screen = SDL_SetVideoMode(640,480,32,SDL_SWSURFACE|SDL_OPENGL);
};
void GameLogic::start()
{
	float angle =0.0;
	const int FPS = 30;
	Uint32 start;
	bool running = true;
	while(running)
	{
		start = SDL_GetTicks();
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					running = false;
					break;
				case SDL_KEYDOWN:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						running = false;
						break;

					
					case SDLK_p:
						cam.mouseIn();
						SDL_ShowCursor(SDL_ENABLE);
						break;

					
				}
				break;
				case SDL_KEYUP:
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						running = false;
						break;

					
					case SDLK_p:
						cam.mouseOut();
						SDL_ShowCursor(SDL_ENABLE);
						break;

				}
				break;
				case SDL_MOUSEBUTTONDOWN:
					cam.mouseIn();
					SDL_ShowCursor(SDL_DISABLE);
					break;
			}
		}
	//handle logic and rfloatendering below 

	update();
	show();

	SDL_GL_SwapBuffers();
	angle+= 0.5;
	if(angle >360)
		angle-=360;
	
	
	// handle framemanagement
	if(1000/FPS > SDL_GetTicks() - start)
		SDL_Delay(1000/FPS -(SDL_GetTicks() - start) );
	}	
};

void GameLogic::update()
{	
	std::vector<collisionplane> cp;
	cp=obj.getCollisionPlane();
	vector3d sphereCenter(10.0,0.0,0.0);
	vector3d rayStart(0.0,0.0,0.0);
	vector3d p1(-5.0,5.0,-5.0);
	vector3d p2(5.0,5.0,-5.0);
	vector3d p3(5.0,-5.0,-5.0);
	vector3d p4(-5.0,-5.0,-5.0);
	vector3d cameraPos = cam.getLocation();
	if(collision::spheresphere(cameraPos,2.0,sphereCenter,1.0))
	std::cout<<"collistion\n";
	//player1->update(obj.getCollisionPlane());
	collision::sphereplane(cameraPos,vector3d(0,0,1),p1,p2,p3,p4,2.0);
	/*for(int i=0;i<cp.size();i++)
		collision::sphereplane(cameraPos,cp[i].normal,cp[i].p[0],cp[i].p[1],cp[i].p[2],cp[i].p[3],2.0); */
        //obj.sphereplane(cameraPos,coordinate(0,0.9701425,0.242535625),p5,p6,p7,p8,2.0);
	cam.setLocation(vector3d(cameraPos));
	 
};

void GameLogic::show()
{
	
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	cam.control();
	cam.update();
	
	vector3d sphereCenter(10.0,0.0,0.0);
	vector3d rayStart(0.0,0.0,0.0);
	vector3d p1(-5.0,5.0,-5.0);
	vector3d p2(5.0,5.0,-5.0);
	vector3d p3(5.0,-5.0,-5.0);
	vector3d p4(-5.0,-5.0,-5.0);
	
	//obj.drawCube(1.0);
	obj.drawPlane(p1,p2,p3,p4);
	glTranslatef(10.0,0.0,0.0);
	obj.drawSphere();
	obj.drawEnvironment();
	
	
	
};



