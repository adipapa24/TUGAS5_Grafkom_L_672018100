#include<windows.h>
#include<gl/glut.h>

int w= 1200 ; int h=600;
int x1=0 , y1= 0, z1=0;
int sudut=0;

int cx, cy;


void init ()
{
       GLfloat LightPosition[] = {10.0f, 10.0f, 20.0f, 0.0f};
       GLfloat LightAmbient [] = {0.0f, 1.0f, 0.0f, 1.0f};
       GLfloat LightDiffuse [] = {0.7f, 0.7f, 0.7f, 1.0f};
       GLfloat LightSpecular[] = {0.5f, 0.5f, 0.5f, 1.0f};
       GLfloat Shine [] = { 80 };

       glShadeModel (GL_SMOOTH );
       glClearColor (0.0f, 0.0f, 0.0f, 0.5f);
       glClearDepth (1.0f);
       glEnable (GL_DEPTH_TEST );
       glHint (GL_PERSPECTIVE_CORRECTION_HINT , GL_NICEST );

       glMaterialfv (GL_FRONT , GL_SPECULAR  , LightSpecular   );
       glMaterialfv (GL_FRONT , GL_SHININESS , Shine);

       glEnable (GL_LIGHTING );
       glEnable (GL_LIGHT0 );
       return;
}

void renderScene ()
{
       GLfloat LightPosition[] = {10.0f, 10.0f, 20.0f, 0.0f};
       glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
       glClearColor (0, 0, 1, 0);
       LightPosition[1] = cx;
       LightPosition[0] = cy;

       glLightfv (GL_LIGHT0 , GL_POSITION , LightPosition );

       glLoadIdentity ();
       glTranslatef (0, 0, -200);
       glRotatef (sudut, x1, y1 , z1);

       glEnable (GL_COLOR_MATERIAL );

       //Tembok rumah
       glPushMatrix ();
              glColor3f (0.5 , 0, 0);
              glTranslatef (0 , 5, 0);
             
              glScalef (25, 18, 15);
              glutSolidCube(3);
       glPopMatrix ();

       //Atap rumah
       glPushMatrix ();
              glColor3f (0 , 0, 0);
              glTranslatef (0 , 32.5, 0);
              glRotatef (45, 1, 0, 0);  
              glScalef (14.8, 7, 7);
              glutSolidCube(5);   
       glPopMatrix ();

       glPushMatrix ();
              glColor3f (0.3 , 0.3, 0);
              glTranslatef (0 , 35, 0);
              glRotatef (45, 1, 0, 0);  
              glScalef (14, 7, 7);
              glutSolidCube(5);   
       glPopMatrix ();

       //Atap tambahan depan
       glPushMatrix ();
              glColor3f (1 , 1, 1);
              glTranslatef (0 , 30, 25);
              glRotatef (90, 0, 0, 1);
              glScalef (1 ,60 , 5);
              glutSolidCube(1.2);
       glPopMatrix ();

       //Atap tambahan belakang
       glPushMatrix ();
              glColor3f (1 , 1, 1);
              glTranslatef (0 , 30, -25);
              glRotatef (90, 0, 0, 1);
              glScalef (1 ,60 , 5);
              glutSolidCube(1.2);
       glPopMatrix ();

       //Pintu 
       glPushMatrix ();
              glColor3f (4 , 0, 0);
              glTranslatef (6 , -10, 22.4);
              glRotatef (90, 0, 1, 0);
              glScalef (1, 20, 10);
              glutSolidCube(1.2);
       glPopMatrix ();

       //Jendela Belakang
       glPushMatrix ();
              glColor3f (4 , 8, 0);
              glTranslatef (-18 , -7, -22);
              glRotatef (90, 0, 1, 0);
              glScalef (2, 9, 5);
              glutSolidCube(1.2);
       glPopMatrix ();


       //Jendela kiri
       glPushMatrix ();
              glColor3f (0 , 0, 0);
              glTranslatef (-38 , -7, 5);
              glScalef (2, 9, 5);
              glutSolidCube(1.2);
       glPopMatrix ();

       //Jendela kanan
       glPushMatrix ();
              glColor3f (4 , 8, 0);
              glTranslatef (38 , -7, -1);
              glScalef (2, 9, 5);
              glutSolidCube(1.2);
       glPopMatrix ();
      
       //Jendela depan kanan
       glPushMatrix ();
              glColor3f (4 , 8, 0);
              glTranslatef (30 , -7, 22);
              glRotatef (90, 0, 1, 0);
              glScalef (2, 9, 5);
              glutSolidCube(1.2);
       glPopMatrix ();

       //Jendela depan kiri
       glPushMatrix ();
              glColor3f (4 , 8, 0);
              glTranslatef (-30 , -7, 22);
              glRotatef (90, 0, 1, 0);
              glScalef (2, 9, 5);
              glutSolidCube(1.2);
       glPopMatrix ();

      
       glDisable (GL_COLOR_MATERIAL );

       glutSwapBuffers ();
}

void resize (int w1, int h1)
{
       glViewport (0, 0 , w1, h1);
       glMatrixMode (GL_PROJECTION );
       glLoadIdentity ();
       gluPerspective (45.0 , (float) w1/ (float) h1, 1.0, 300.0);
       glMatrixMode (GL_MODELVIEW );
       glLoadIdentity ();
}

void myKeyboard (unsigned char  key, int x, int y)// Fungsi keyboard
{
       switch (key)
       {
              case 'x' :// Fungsinya untuk memutar dari atas ke bawah
                     x1 = 1;
                     y1 = 0;
                     z1 = 0;
                     sudut+=-10;
                     break ;
              case 'y' :// Fungsinya untuk memutar dari kiri ke kanan
                     x1 = 0;
                     y1 = 1;
                     z1 = 0;
                     sudut+=-10;
                     break ;
              case 'z' :// Funsingya untuk memutar dari kanan ke kiri tapibagian depan tidak berpindah
                     x1 = 0;
                     y1 = 0;
                     z1 = 1;
                     sudut+=-10;
                     break ;
       }
}

void mouse(int tombol, int state, int x, int y){// Fungsi mouse
cx = x-(w/2);
cy = (h/2)-y;
}

void motion (int x, int y)
{
 cx = x-(w/2);
 cy = (h/2)-y;
}

void update(int value)
{
       glutPostRedisplay ();
       glutTimerFunc (50 , update , 0);
}

int main (int argc, char **argv)
{
       glutInit (&argc, argv);
       glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA );
       glutInitWindowPosition (10, 10);
       glutInitWindowSize (w ,h);
       glutCreateWindow ("Julian Lirama Junor Pandari - 672018100");

       glutReshapeFunc (resize);
       glutDisplayFunc (renderScene);
       glutMouseFunc(mouse);
       glutMotionFunc(motion);
       glutTimerFunc (50, update , 0);
       glutKeyboardFunc (myKeyboard );
       init ();
       glutMainLoop ();
}

