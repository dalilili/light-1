#include <GL/glut.h>

#define WIDTH 640
#define HEIGHT 480

static GLfloat angle = 30.0f;

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// ����͸��Ч����ͼ
	glMatrixMode(GL_PROJECTION);//����Ҫ��ͶӰ��ؽ��в�����Ҳ���ǰ�����ͶӰ��һ��ƽ���ϣ�������������һ������3ά����Ͷ��2ά��ƽ���ϡ����������������������Ǹ�͸����صĺ���������glFrustum()��gluPerspective()��
	glLoadIdentity();//���õ�ǰָ���ľ���Ϊ��λ����
	gluPerspective(90.0f, 1.0f, 1.0f, 20.0f); // oid gluPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar)near �� far ������ͶӰ�ο�����ü����ڵľ��룬fovy�����˲ü����ڵĸ߶ȣ����и����� aspect ȷ���˲ü����ڵĳ��������

		glMatrixMode(GL_MODELVIEW);//����Ƕ�ģ���Ӿ��Ĳ�������������������һ����ģ��Ϊ��������Ӧ�����������ò������������õ��ľ�����gluLookAt()�����ĺ�����
	glLoadIdentity();
	gluLookAt(0.0, 5.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	
	{
		GLfloat sun_light_position[] = { 1.0f, 1.0f, 0.0f, 0.0f };
		GLfloat sun_light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; //RGBAģʽ�Ļ����⣬Ϊ0  
		GLfloat sun_light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; //RGBAģʽ��������⣬ȫ�׹�  
		GLfloat sun_light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

		glLightfv(GL_LIGHT0, GL_POSITION, sun_light_position);//ʹ��GL_LIGHT0��ʾ��0�Ź�Դ��GL_LIGHT1��ʾ��1�Ź�Դ���������ƣ�OpenGL���ٻ�֧��8����Դ����GL_LIGHT0��GL_LIGHT7��ʹ��glEnable�������Կ������ǡ�
		glLightfv(GL_LIGHT0, GL_AMBIENT, sun_light_ambient);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, sun_light_diffuse);
		glLightfv(GL_LIGHT0, GL_SPECULAR, sun_light_specular);

		glEnable(GL_LIGHT0);//������0�Ź�Դ,ʹ��glDisable��������Թرչ�Դ
		glEnable(GL_LIGHTING);//Ҫ�򿪹��մ����ܣ�ʹ�����������
		glEnable(GL_DEPTH_TEST);
	}


	{
		GLfloat sun_mat_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat sun_mat_diffuse[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat sun_mat_specular[] = { 0.0f, 0.0f, 0.0f, 0.0f };
		GLfloat sun_mat_emission[] = { 0.5f, 0.0f, 0.0f, 1.0f };
		GLfloat sun_mat_shininess = 0.0f;
		glMaterialfv(GL_FRONT, GL_AMBIENT, sun_mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, sun_mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, sun_mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, sun_mat_emission);//GL_EMISSION���ԡ����������ĸ�ֵ��ɣ���ʾһ����ɫ��OpenGL��Ϊ�ò��ʱ����΢΢�����ⷢ����ߣ��������۾��о���������������ɫ����������ֱȽ�΢���������ڲ���Ӱ�쵽�����������ɫ��
		glMaterialf(GL_FRONT, GL_SHININESS, sun_mat_shininess);

		
	}

	// �������Ĳ��ʲ����Ƶ���
	{
		GLfloat earth_mat_ambient[] = { 0.0f, 0.0f, 0.5f, 1.0f };
		GLfloat earth_mat_diffuse[] = { 0.0f, 0.0f, 0.5f, 1.0f };
		GLfloat earth_mat_specular[] = { 0.0f, 0.0f, 1.0f, 1.0f };
		GLfloat earth_mat_emission[] = { 0.0f, 0.0f, 0.0f, 1.0f };
		GLfloat earth_mat_shininess = 50.0f;

		glMaterialfv(GL_FRONT, GL_AMBIENT, earth_mat_ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, earth_mat_diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, earth_mat_specular);
		glMaterialfv(GL_FRONT, GL_EMISSION, earth_mat_emission);
		glMaterialf(GL_FRONT, GL_SHININESS, earth_mat_shininess);

		
		glTranslatef(3.0f, 0.0f, 0.0f);
		glutSolidSphere(4.0, 50, 32);
	}

	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("gouraud����ģ��");
	glutDisplayFunc(&myDisplay);
	glutMainLoop();
	return 0;
}