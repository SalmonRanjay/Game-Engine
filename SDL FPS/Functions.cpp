#include "Functions.h"

Functions::Functions()
{
	camX = 0.0;
	camY = 0.0 ;
	camZ = 0.0 ;
	camYaw = 0.0 ;
	camPitch = 0.0 ;
	mousein = false ;
};

unsigned int Functions::loadTexture(const char* filename)
{
	SDL_Surface* img=SDL_LoadBMP(filename);
	unsigned int id;
	glGenTextures(1,&id);
	glBindTexture(GL_TEXTURE_2D,id);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,img->w,img->h,0,GL_RGB,GL_UNSIGNED_SHORT_5_6_5,img->pixels);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	SDL_FreeSurface(img);
	return id;
};

void Functions::lockCamera()
{
	if(camPitch>90)
		camPitch=90;
	if(camPitch<= -90)
		camPitch = -90;
	if(camYaw < 0.0)
		camYaw += 360.0;
	if(camYaw > 360)
		camYaw -= 360;
};

void Functions:: moveCamera(float dist,float dir)
{
	float rad=(camYaw + dir)*T_PI/180.0;
	camX-= sin(rad)*dist;
	camZ-= cos (rad)*dist;
};

void Functions:: moveCameraUp(float dist, float dir)
{
	float rad = (camPitch + dir)*T_PI /180;
	camY += sin(rad)*dist;
};

void Functions:: Control(float movevel,float mousevel, bool mi)
{
	int tmpx,tmpy;
	int midX = 320;
	int midY = 240;
	if(mi)
	{
		SDL_ShowCursor(SDL_DISABLE);
		SDL_GetMouseState(&tmpx,&tmpy);//SDL Command to get mouse x and y pos
		camYaw += mousevel *(midX-tmpx);
		camPitch += mousevel* (midY - tmpy);
		lockCamera();
		SDL_WarpMouse(midX,midY);//set cursor back to center
		Uint8* state = SDL_GetKeyState(NULL);
		if(state[SDLK_w])
		{
			//if(camPitch != 90 && camPitch != -90) // lock the camera from moving off into space
				moveCamera(movevel,0.0);
				//moveCameraUp(movevel,0.0); // lock the camera from moving off into space
		}
		else if(state[SDLK_s])
		{
			//if(camPitch != 90 && camPitch != -90) // lock the camera from moving off into space comment here
				moveCamera(movevel,180.0);
			//	moveCameraUp(movevel,180.0); // lock the camera from moving off into space comment this line
		}
		if (state[SDLK_a])
			moveCamera(movevel,90);
		else if(state[SDLK_d])
			moveCamera(movevel,270);
	}
	glRotatef(-camPitch,1.0,0.0,0.0);
	glRotatef(-camYaw,0.0,1.0,0.0);
};

void Functions::updateCamera()
{
	glTranslatef(-camX,-camY,-camZ);
};

void Functions:: drawCube(float size)
{
	float difamb[]={1.0,0.5,0.3,1.0};
	glBegin(GL_QUADS);
	// front face
	//glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE,difamb);
	glNormal3f(0.0,0.0,1.0);
	glColor3f(   1.0,  0.0, 0.0 );
	glVertex3f(  size/2, size/2, size/2 );
	glVertex3f(  -size/2,  size/2, size/2 );
	glVertex3f( -size/2,  -size/2, size/2 );
	glVertex3f( size/2, -size/2, size/2 );

	// left face
	glNormal3f(-1.0,0.0,0.0);
	glColor3f(  0.0,  1.0,  0.0 );
	glVertex3f( -size/2, size/2, size/2 );
	glVertex3f( -size/2,  size/2, -size/2 );
	glVertex3f( -size/2, -size/2,  -size/2 );
	glVertex3f( -size/2, -size/2,  size/2 );
	
	 
	// BACK FACE
	glNormal3f(0.0,0.0,-1.0);
	glColor3f(   0.0,  0.0,  1.0 );
	glVertex3f( size/2, size/2,  -size/2 );
	glVertex3f( -size/2,  size/2,  -size/2 );
	glVertex3f( -size/2,  -size/2, -size/2 );
	glVertex3f( size/2, -size/2, -size/2 );
	 
	// RIGHT FACE
	glNormal3f(1.0,0.0,0.0);
	glColor3f(   2.0,  1.0,  1.0 );
	glVertex3f(  size/2,  size/2,  -size/2 );
	glVertex3f(  size/2,  size/2, size/2 );
	glVertex3f(  size/2,  -size/2, size/2 );
	glVertex3f(  size/2,  -size/2, -size/2 );
	
	 
	// TOP FACE
	glNormal3f(0.0,1.0,0.0);
	glColor3f(   1.0,  0.0,  1.0 );
	glVertex3f(  size/2, size/2, size/2 );
	glVertex3f(  -size/2, size/2,  size/2 );
	glVertex3f( -size/2, size/2,  -size/2 );
	glVertex3f( size/2, size/2, -size/2 );
	
	//BOTTOM FACE
	glNormal3f(0.0,-1.0,0.0);
	glColor3f(1.0,3.0,1.0);
	glVertex3f(  size/2, -size/2, size/2 );
	glVertex3f(  -size/2, -size/2,  size/2 );
	glVertex3f( -size/2, -size/2,  -size/2 );
	glVertex3f( size/2, -size/2, -size/2 );

	glEnd();
};

bool Functions:: raySphereIntersection(float xc,float yc,float zc,float xd, float yd, float zd, float xs, float ys, float zs, float r,float* dist, vector3d* point)
{
	float b = 2*(xd *(xs-xc)+yd * (ys - yc)+ zd * (zs-zc));
	float c = xs*xs - 2 *xs * xc + xc +ys *ys -2 * ys*yc +yc*yc +zs *zs -2* zs*zc+zc*zc-r*r;
	float disc = (b*b-4*c);
	if(disc < 0)
		return false;
	if(dist!= NULL)
	{
		(*dist)=(-b + sqrt(disc))/2;
		 if(point!=NULL)
                {
                        //xs+t*xd
                        point->x=xs+(*dist)*xd;
                        point->y=ys+(*dist)*yd;
                        point->z=zs+(*dist)*zd;
                }
	} 
	return true;
};

void Functions::drawSphere()
{
	float angle1, angle2;
	float xx,yy,zz,xxp,yyp,zzp;
	
	
	glPushMatrix();
	
	for(angle2 = -T_PI/2 ; angle2<=T_PI/2; angle2+= RESL)
	{
		glBegin(GL_QUAD_STRIP);
		for(angle1 =0.0 ; angle1 <=T_PI*2.0 + RESL ; angle1 += RESL)
		{
			yy = sin(angle2);
			xx = cos(angle1) * cos(angle2);
			zz = sin(angle1) * cos(angle2);
			
			yyp = sin(angle2 + RESL);
			xxp = cos(angle1) * cos(angle2 + RESL);
			zzp = sin(angle1) * cos(angle2 + RESL);

			glColor3f(0.0,1.0,0.0); 
			glVertex3f(xx,yy,zz);
			glColor3f(0.0,0.0,1.0);
			glVertex3f(xxp,yyp,zzp);
		}
		glEnd();
	}
	glPopMatrix();
};

void Functions::drawEnvironment()
{
	glPushMatrix();
	glColor3f(0.09f, 0.9f,0.9f);
	glBegin(GL_QUADS);
			glVertex3f(-100.0f,-1.0f,-100.0f);
			glVertex3f(-100.0f,-1.0f,100.0f);
			glVertex3f(100.0f,-1.0f,100.0f);
			glVertex3f(100.0f,-1.0f,-100.0f);
		glEnd();
	glPopMatrix();
};



float Functions:: trianglearea(vector3d p1,vector3d p2,vector3d p3)
{
        //area of the triangle with the heron fomula
        float a=sqrt((p2.x-p1.x)*(p2.x-p1.x)+(p2.y-p1.y)*(p2.y-p1.y)+(p2.z-p1.z)*(p2.z-p1.z));
        float b=sqrt((p3.x-p2.x)*(p3.x-p2.x)+(p3.y-p2.y)*(p3.y-p2.y)+(p3.z-p2.z)*(p3.z-p2.z));
        float c=sqrt((p1.x-p3.x)*(p1.x-p3.x)+(p1.y-p3.y)*(p1.y-p3.y)+(p1.z-p3.z)*(p1.z-p3.z));
        float s=(a+b+c)/2.;
        return (sqrt(s*((s-a)*(s-b)*(s-c))));
 
}

bool Functions:: rayplane(float nx,float ny,float nz,float xs,float ys,float zs,float xd,float yd,float zd,vector3d p1,vector3d p2,vector3d p3,vector3d p4,float* dist, vector3d* point)
{
        float a=xd*nx+yd*ny+zd*nz;
        if(a==0)
                return false; // check if ray is parrellel to plane return false they will never touch
        float t=((p1.x*nx+p1.y*ny+p1.z*nz-nx*xs-ny*ys-nz*zs)/a);
        if(t<0)
                return false; // return false if collision happens behind the place
        float x=xs+t*xd;
        float y=ys+t*yd;
        float z=zs+t*zd;
        vector3d cp(x,y,z);
        if(abs(trianglearea(p1,p3,p4)-trianglearea(p1,p4,cp)-trianglearea(p1,p3,cp)-trianglearea(p3,p4,cp))<0.000001 || abs(trianglearea(p1,p2,p3)-trianglearea(p1,p2,cp)-trianglearea(p2,p3,cp)-trianglearea(p1,p3,cp))<0.000001)
	 {
                if(dist!=NULL)
                {
                        (*dist)=t;
                        if(point!=NULL)
                        {
                                point->x=x;
                                point->y=y;
                                point->z=z;
                        }
                }
                return true;
        }
        return false;
};

void Functions:: drawPlane(vector3d p1, vector3d p2, vector3d p3,vector3d p4)
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);
		glVertex3f(p1.x, p1.y,p1.z);
		glVertex3f(p2.x, p2.y,p2.z);
		glVertex3f(p3.x, p3.y,p3.z);
		glVertex3f(p4.x, p4.y,p4.z);	
	glEnd();
};


bool Functions:: spheresphere(vector3d& c1,float r1,vector3d c2,float r2)
{
        float dist=pointdistance(c1,c2);
        if(dist<=(r1+r2)*(r1+r2))
        {
                float a=sqrt(dist)-(r1+r2);
                vector3d vec(c2.x-c1.x,c2.y-c1.y,c2.z-c1.z);  //c2-c1
                float len=sqrt((vec.x*vec.x+vec.y*vec.y+vec.z*vec.z));
                vec.x/=len;
                vec.y/=len;
                vec.z/=len;
                c1.x=c1.x+vec.x*a;
                c1.y=c1.y+vec.y*a;
                c1.z=c1.z+vec.z*a;
                return 1;
        }
        return 0;
}


float Functions:: pointdistance(vector3d c1,vector3d c2)
{
        vector3d vec(c2.x-c1.x,c2.y-c1.y,c2.z-c1.z);
        return (vec.x*vec.x+vec.y*vec.y+vec.z*vec.z);
}

void Functions:: moveTo(vector3d c)
{
        camX=c.x;
        camY=c.y;
        camZ=c.z;
}
vector3d Functions:: camPos()
{
        return (vector3d(camX,camY,camZ));
}
 

bool Functions:: sphereplane(vector3d& sp, vector3d vn,vector3d p1,vector3d p2,vector3d p3, vector3d p4,float r)
{
        //float nx,float ny,float nz,float xs,float ys,float zs,float xd,float yd,float zd,vector3d p1,vector3d p2,vector3d p3,vector3d p4,float* dist,coordinate* point)
        float dist1=0,dist2=0;
        if(rayplane(-vn.x,-vn.y,-vn.z,sp.x,sp.y,sp.z,vn.x,vn.y,vn.z,p1,p2,p3,p4,&dist1) || rayplane(vn.x,vn.y,vn.z,sp.x,sp.y,sp.z,-vn.x,-vn.y,-vn.z,p1,p2,p3,p4,&dist2))
        {
                if(dist1>r || dist2>r)
                        return false;
                if(dist1>0)
                {
                        //sp.x=sp.x-vn.x*(r-dist1);
                        sp.y=sp.y-vn.y*(r-dist1);
                        sp.z=sp.z-vn.z*(r-dist1);
                }else{
                        //sp.x=sp.x+vn.x*(r-dist2);
                        sp.y=sp.y+vn.y*(r-dist2);
                        sp.z=sp.z+vn.z*(r-dist2);              
                }
                return 1;
        }
        return 0;
} 
