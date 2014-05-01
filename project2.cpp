#include "initShaders.h"
#include <cstdlib>
using namespace std;

void rotate(GLuint locate);

GLuint 	vaoID,vboID[2],eboID,
	vaoID2,vboID2[2],eboID2,
	vaoID3,vboID3[2],eboID3,
	vaoID4,vboID4[2],eboID4,
        vaoID5,vboID5[2],eboID5,
	vaoID6,vboID6[2],eboID6,
        vaoID7,vboID7[2],eboID7,
	vaoID8,vboID8[2],eboID8,
        vaoID9,vboID9[2],eboID9,
	vaoID10,vboID10[2],eboID10,
        vaoID11,vboID11[2],eboID11;
GLuint program;

GLfloat pit,yaw,scalar=1;
glm::vec3 cubeTran, cubeTran2, cameraTran;

GLfloat size=6;

GLfloat vertexarray[]={-19,-19,-6,
                       -19,-25,-6,
                       -25,-25,-6,
                       -25,-19,-6,
                       -19,-19,0,
                       -19,-25,0,
                       -25,-25,0,
                       -25,-19,0
                       };
GLfloat vertexarray2[]={-25,-25,-20,
                       -25,-26,-20,
                       -15,-26,-20,
                       -15,-25,-20,
                       -25,-25,0,
                       -25,-26,0,
                       -15,-26,-0,
                       -15,-25,-0
                       };
GLfloat vertexarray4[]={-25,-25,-20,
                       -25,-26,-20,
                       15,-26,-20,
                       15,-25,-20,
                       -25,-25,-40,
                       -25,-26,-40,
                       15,-26,-40,
                       15,-25,-40
                       };
GLfloat vertexarray5[]={-5,-25,-40,
                       -5,-26,-40,
                       15,-26,-40,
                       15,-25,-40,
                       -5,-25,-50,
                       -5,-26,-50,
                       15,-26,-50,
                       15,-25,-50
                       };
GLfloat vertexarray6[]={-25,-25,-50,
                       -25,-26,-50,
                       15,-26,-50,
                       15,-25,-50,
                       -25,-25,-70,
                       -25,-26,-70,
                       15,-26,-70,
                       15,-25,-70
                       };
GLfloat vertexarray7[]={-25,-25,-90,
                       -25,-26,-90,
                       -10,-26,-90,
                       -10,-25,-90,
                       -25,-25,-70,
                       -25,-26,-70,
                       -10,-26,-70,
                       -10,-25,-70
                       };
GLfloat vertexarray8[]={0,-25,-90,
                       0,-26,-90,
                       15,-26,-90,
                       15,-25,-90,
                       -0,-25,-70,
                       -0,-26,-70,
                       15,-26,-70,
                       15,-25,-70
                       };
GLfloat vertexarray9[]={-25,-25,-90,
                       -25,-26,-90,
                       15,-26,-90,
                       15,-25,-90,
                       -25,-25,-100,
                       -25,-26,-100,
                       15,-26,-100,
                       15,-25,-100
                       };
GLfloat vertexarray10[]={-25,-25,-110,
                       -25,-19,-110,
                       -19,-19,-110,
                       -19,-25,-110,
                       -25,-25,-116,
                       -25,-19,-116,
                       -19,-19,-116,
                       -19,-25,-116
                       };
GLfloat vertexarray11[]={9,-25,-110,
                       9,-19,-110,
                       15,-19,-110,
                       15,-25,-110,
                       9,-25,-116,
                       9,-19,-116,
                       15,-19,-116,
                       15,-25,-116
                       };




GLfloat vertexarray3[]={-50,-25,-100,
                       -50,-26,-100,
                       30,-26,-100,
                       30,-25,-100,
                       -50,-25,-120,
                       -50,-26,-120,
                       30,-26,-120,
                       30,-25,-120
                       };

GLfloat colorarray[]={0.9f,0.6f,0.4f,1.0f,
                      0.5f,0.2f,0.6f,1.0f,
                      0.7f,0.4f,0.2f,1.0f,
                      0.6f,0.3f,0.5f,1.0f,
                      0.8f,0.7f,0.3f,1.0f,
                      0.4f,0.8f,0.9f,1.0f,
                      0.3f,0.5f,0.8f,1.0f,
                      0.2f,0.9f,0.7f,1.0f
                                        };

GLfloat colorarray2[]={0.0f,1.0f,1.0f,1.0f,
                      1.0f,1.0f,0.0f,1.0f,
                      0.0f,1.0f,1.0f,1.0f,
                      1.0f,1.0f,0.0f,1.0f,
		      0.0f,1.0f,1.0f,1.0f,
                      1.0f,1.0f,0.0f,1.0f,
                      0.0f,1.0f,1.0f,1.0f,
                      1.0f,1.0f,0.0f,1.0f

                                        };

GLfloat colorarray3[]={0.0f,0.0f,1.0f,1.0f,
                      0.0f,0.0f,0.5f,1.0f,
                      0.0f,0.0f,1.0f,1.0f,
                      0.0f,0.0f,0.5f,1.0f,
                      0.0f,0.0f,1.0f,1.0f,
                      0.0f,0.0f,0.5f,1.0f,
                      0.0f,0.0f,1.0f,1.0f,
                      0.0f,0.0f,0.5f,1.0f

                                        };
GLfloat colorarray4[]={0.5f,0.0f,0.0f,1.0f,
                      1.0f,0.0f,0.0f,1.0f,
                      0.5f,0.0f,0.0f,1.0f,
                      1.0f,0.0f,0.0f,1.0f,
                      0.5f,0.0f,0.0f,1.0f,
                      1.0f,0.0f,0.0f,1.0f,
                      0.5f,0.0f,0.0f,1.0f,
                      1.0f,0.0f,0.0f,1.0f

                                        };



 GLubyte elems[]={0,1,2,3,7,4,5,6,
                  7,3,0,4,5,6,2,1,
                  0,1,5,4,7,3,2,6
                 };

void init(){
         glEnable(GL_DEPTH_TEST);
         glViewport(0, 0, 600, 600);

        glGenVertexArrays(1,&vaoID);
        glBindVertexArray(vaoID);

        glGenBuffers(2, vboID);
        glBindBuffer(GL_ARRAY_BUFFER,vboID[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray),vertexarray,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID[1]);
  	glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray),colorarray,GL_STATIC_DRAW);
  	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

  	glGenBuffers(1,&eboID);
  	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID);
  	glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glGenVertexArrays(1,&vaoID2);
        glBindVertexArray(vaoID2);

        glGenBuffers(2, vboID2);
        glBindBuffer(GL_ARRAY_BUFFER,vboID2[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray2),vertexarray2,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID2[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray2),colorarray2,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glGenBuffers(1,&eboID2);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID2);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);
        
	glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1,&vaoID3);
        glBindVertexArray(vaoID3);

        glGenBuffers(2, vboID3);
        glBindBuffer(GL_ARRAY_BUFFER,vboID3[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray3),vertexarray3,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID3[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray2),colorarray2,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glGenBuffers(1,&eboID3);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID3);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1,&vaoID4);
        glBindVertexArray(vaoID4);

        glGenBuffers(2, vboID4);
        glBindBuffer(GL_ARRAY_BUFFER,vboID4[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray4),vertexarray4,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID4[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray2),colorarray2,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glGenBuffers(1,&eboID4);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID4);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1,&vaoID5);
        glBindVertexArray(vaoID5);

        glGenBuffers(2, vboID5);
        glBindBuffer(GL_ARRAY_BUFFER,vboID5[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray5),vertexarray5,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID5[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray2),colorarray2,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glGenBuffers(1,&eboID5);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID5);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1,&vaoID6);
        glBindVertexArray(vaoID6);

        glGenBuffers(2, vboID6);
        glBindBuffer(GL_ARRAY_BUFFER,vboID6[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray6),vertexarray6,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID6[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray2),colorarray2,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glGenBuffers(1,&eboID6);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID6);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1,&vaoID7);
        glBindVertexArray(vaoID7);

        glGenBuffers(2, vboID7);
        glBindBuffer(GL_ARRAY_BUFFER,vboID7[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray7),vertexarray7,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID7[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray2),colorarray2,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glGenBuffers(1,&eboID7);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID7);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1,&vaoID8);
        glBindVertexArray(vaoID8);

        glGenBuffers(2, vboID8);
        glBindBuffer(GL_ARRAY_BUFFER,vboID8[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray8),vertexarray8,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID8[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray2),colorarray2,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glGenBuffers(1,&eboID8);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID8);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1,&vaoID9);
        glBindVertexArray(vaoID9);

        glGenBuffers(2, vboID9);
        glBindBuffer(GL_ARRAY_BUFFER,vboID9[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray9),vertexarray9,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID9[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray2),colorarray2,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glGenBuffers(1,&eboID9);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID9);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1,&vaoID10);
        glBindVertexArray(vaoID10);

        glGenBuffers(2, vboID10);
        glBindBuffer(GL_ARRAY_BUFFER,vboID10[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray10),vertexarray10,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID10[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray3),colorarray3,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glGenBuffers(1,&eboID10);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID10);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        glGenVertexArrays(1,&vaoID11);
        glBindVertexArray(vaoID11);

        glGenBuffers(2, vboID11);
        glBindBuffer(GL_ARRAY_BUFFER,vboID11[0]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(vertexarray11),vertexarray11,GL_STATIC_DRAW);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ARRAY_BUFFER, vboID11[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(colorarray4),colorarray4,GL_STATIC_DRAW);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, (void*)0);

        glGenBuffers(1,&eboID11);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID11);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(elems),elems,GL_STATIC_DRAW);	

	ShaderInfo shaders[]={
  { GL_VERTEX_SHADER , "vertexshader.glsl"},
  { GL_FRAGMENT_SHADER , "fragmentshader.glsl"},
  { GL_NONE , NULL}
  };

  program=initShaders(shaders);

  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);

  GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color(0.2, 0.2, 0.2)
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

  GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
    GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

  GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

}


void display(SDL_Window* screen){
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

        glm::mat4 trans, trans2;
        /*
        trans=glm::translate(trans,cubeTran);
        trans=glm::rotate(trans,pit,glm::vec3(1,0,0));
        trans=glm::rotate(trans,yaw,glm::vec3(0,1,0));
        trans=glm::translate(trans,cubeTran);
        trans=glm::scale(trans,glm::vec3(scalar));
        */

        trans=glm::translate(trans,cameraTran);
        trans=glm::rotate(trans,pit,glm::vec3(1,0,0));
        trans=glm::rotate(trans,yaw,glm::vec3(0,1,0));
        trans=glm::translate(trans,cameraTran);
        trans=glm::scale(trans,glm::vec3(scalar));

  	GLint tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans[0][0]);

	glBindVertexArray(vaoID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID);
        glDrawElements(GL_POLYGON,24,GL_UNSIGNED_BYTE,NULL);

	// draw second object
        trans2=glm::translate(trans2,cubeTran);

  	tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans2[0][0]);

	glBindVertexArray(vaoID2);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID2);
        glDrawElements(GL_POLYGON,24,GL_UNSIGNED_BYTE,NULL);

	// draw third object
        trans2=glm::translate(trans2,cubeTran);

        tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans2[0][0]);

        glBindVertexArray(vaoID3);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID3);
        glDrawElements(GL_POLYGON,24,GL_UNSIGNED_BYTE,NULL);

	 // draw forth object
        trans2=glm::translate(trans2,cubeTran);

        tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans2[0][0]);

        glBindVertexArray(vaoID4);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID4);
        glDrawElements(GL_POLYGON,24,GL_UNSIGNED_BYTE,NULL);

	 // draw fifth object
        trans2=glm::translate(trans2,cubeTran);

        tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans2[0][0]);

        glBindVertexArray(vaoID5);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID5);
        glDrawElements(GL_POLYGON,24,GL_UNSIGNED_BYTE,NULL);

	 // draw sixth object
        trans2=glm::translate(trans2,cubeTran);

        tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans2[0][0]);

        glBindVertexArray(vaoID6);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID6);
        glDrawElements(GL_POLYGON,24,GL_UNSIGNED_BYTE,NULL);
	
	// draw seventh object
        trans2=glm::translate(trans2,cubeTran);

        tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans2[0][0]);

        glBindVertexArray(vaoID7);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID7);
        glDrawElements(GL_POLYGON,24,GL_UNSIGNED_BYTE,NULL);

	// draw eith object
        trans2=glm::translate(trans2,cubeTran);

        tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans2[0][0]);

        glBindVertexArray(vaoID8);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID8);
        glDrawElements(GL_POLYGON,24,GL_UNSIGNED_BYTE,NULL);

	// draw ninth object
        trans2=glm::translate(trans2,cubeTran);

        tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans2[0][0]);

        glBindVertexArray(vaoID9);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID9);
        glDrawElements(GL_POLYGON,24,GL_UNSIGNED_BYTE,NULL);

	// draw Tenth object
        trans2=glm::translate(trans2,cubeTran);

        tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans2[0][0]);

        glBindVertexArray(vaoID10);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID10);
        glDrawElements(GL_POLYGON,24,GL_UNSIGNED_BYTE,NULL);

	// draw eleven object
        trans2=glm::translate(trans2,cubeTran);

        tempLoc = glGetUniformLocation(program,"modelMatrix");
        glUniformMatrix4fv(tempLoc,1,GL_FALSE,&trans2[0][0]);

        glBindVertexArray(vaoID11);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboID11);
        glDrawElements(GL_POLYGON,24,GL_UNSIGNED_BYTE,NULL);


        glFlush();
        SDL_GL_SwapWindow(screen);
}

void input(SDL_Window* screen){

SDL_Event event;
/*
        while (SDL_PollEvent(&event)){
                switch (event.type){
                        case SDL_QUIT:exit(0);break;
                        case SDL_KEYDOWN:
                                switch(event.key.keysym.sym){
                                        case SDLK_ESCAPE:exit(0);
                                        case SDLK_w:cubeTran.y+=2;break;
                                        case SDLK_s:cubeTran.y-=2;break;
                                        case SDLK_a:cubeTran.x-=2;break;
                                        case SDLK_d:cubeTran.x+=2;break;
                                        case SDLK_e:scalar+=.1f;break;
                                        case SDLK_q:scalar-=.1f;break;
                                        case SDLK_i:pit+=2;break;
                                        case SDLK_k:pit-=2;break;
                                        case SDLK_j:yaw+=2;break;
                                        case SDLK_l:yaw-=2;break;
                                }
                }
        }
}
*/
 int counter = 0;
 while (SDL_PollEvent(&event)){
		if(counter == 1)
		{
			cout << "You took the Blue Pill. You Win!!! \n";
			exit(0);
			break;
		}
		if(counter == 2)
		{
			cout << "You took the Red Pill. You Lose!!! \n";
			exit(0);
			break;
		} 
                switch (event.type){

                        case SDL_QUIT:exit(0);break;
                        case SDL_KEYDOWN:
                                switch(event.key.keysym.sym){
                                        case SDLK_ESCAPE:exit(0);
                                        case SDLK_w:cameraTran.z-=2;break;
                                        //case SDLK_s:cameraTran.y-=2;break;
                                        case SDLK_a:cameraTran.x-=2;cameraTran.z-=2;break;
                                        case SDLK_d:cameraTran.x+=2;cameraTran.z-=2;break;
                                        //case SDLK_e:scalar+=.1f;break;
                                        //case SDLK_q:scalar-=.1f;break;
                                        //case SDLK_i:pit+=2;break;
                                        //case SDLK_k:pit-=2;break;
                                        //case SDLK_j:yaw+=2;break;
                                        //case SDLK_l:yaw-=2;break;
					default: break;
                                }
				if((cameraTran.x < 0 || cameraTran.x > 2) && cameraTran.z >-10)
				{
					cameraTran.x = 0;
					cameraTran.z = 0;
				}
				else if(cameraTran.x < 0 && cameraTran.z > -48)
                                {
                                        cameraTran.x = 0;
                                        cameraTran.z = 0;
                                }
				else if((cameraTran.z < -16 && cameraTran.z > -26) && cameraTran.x < 10)
                                {
                                        cameraTran.x = 0;
                                        cameraTran.z = 0;
                                }
				else if((cameraTran.x > 4 && cameraTran.x < 14) && cameraTran.z < -32)
                                {
                                        cameraTran.x = 0;
                                        cameraTran.z = 0;
                                }
				else if(cameraTran.z < -58)
                                {
                                        cameraTran.x = 0;
                                        cameraTran.z = 0;
                                }
				else if(cameraTran.x > 16)
                                {
                                        cameraTran.x = 0;
                                        cameraTran.z = 0;
                                }
				else if((cameraTran.x >= 0 && cameraTran.x < 3) && cameraTran.z <= -52)
				{
					counter = 1;
					break;
				}
				else if((cameraTran.x > 13 && cameraTran.x < 17) && cameraTran.z <= -52)
                                {
                                        counter = 2;
                                        break;
                                }

		}
                
        }
}




int main(int argc, char **argv){

        SDL_Window *window;

        if(SDL_Init(SDL_INIT_VIDEO)<0){
                fprintf(stderr,"Unable to create window: %s\n", SDL_GetError());
    SDL_Quit();
    exit(1);
        }

        window = SDL_CreateWindow(
                "Happy Days",
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                500,
                500,
                SDL_WINDOW_OPENGL
        );

        if(window==NULL){
                fprintf(stderr,"Unable to create window: %s\n",SDL_GetError());
        }


        SDL_GLContext glcontext=SDL_GL_CreateContext(window);

  glewExperimental=GL_TRUE;
  if(glewInit()){
    fprintf(stderr, "Unable to initalize GLEW");
    exit(EXIT_FAILURE);
  }

        init();

        while(true){
          input(window);
                display(window);
        }

        SDL_GL_DeleteContext(glcontext);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
