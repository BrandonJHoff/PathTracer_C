#include "Scene.h"

Scene loadScene(char* filename){
    Scene scene = {};
    scene.max_depth = 10;
    scene.num_samples = 4;

    scene.image = createImage(500, 500);

    Vector position = {278, 273, -800};
    Vector look_at = {278, 273, 0};
    Vector up = {0, 1, 0};
    scene.camera = createCamera(position, look_at, up, 39, (float)(scene.image.width/scene.image.height));

    Color red = {255, 0, 0};
    Color green = {0, 255, 0};
    Color white = {255, 255, 255};

    scene.num_triangles = 4;
    scene.triangles = malloc(scene.num_triangles * sizeof(Triangle));
    scene.triangles[0] = createTriangle(red, createVector(0.0, 0.0, 559.2), createVector(0.0, 0.0, 0.0), createVector(0.0, 548.8, 0.0));
    scene.triangles[1] = createTriangle(green, createVector(0.0, 0.0, 559.2), createVector(0.0, 548.8, 0.0), createVector(0.0, 548.8, 559.2));

    scene.triangles[2] = createTriangle(white, createVector(552.8, 0.0, 0.0), createVector(0.0, 0.0, 0.0), createVector(0.0, 0.0, 559.2));
    scene.triangles[3] = createTriangle(white, createVector(552.8, 0.0, 0.0), createVector(0.0, 0.0, 559.2), createVector(552.8, 0.0, 559.2));

    return scene;
}

void renderScene(Scene* scene){
	Color result;
	HitRecord record;

    Color black = {0, 0, 0};
    Color red = {255, 0, 0};

    int xres = scene->image.width;
    int yres = scene->image.height;

	for(int i = 0; i < xres; i++){
		for(int j = 0; j < yres; j++){

			double x = 2 * (i - xres/2. + 0.5)/xres;
			double y = 2 * (j - yres/2. + 0.5)/yres;

            Ray ray = cameraCreateRay(scene->camera, x, -y);
            resetHitRecord(&record);
            result = black;

            for(int k = 0; k < scene->num_triangles; k++){
        		if(hitTriangle(&scene->triangles[k], &record, &ray)){
        			result = record.triangle->color;
        		}
        	}

			setImageColor(&scene->image, i, j, result);
		}
	}
}
