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

    Color red = {.95, .25, .25};
    Color green = {.25, .95, .25};
    Color white = {.95, .95, .85};
    Color blue = {.25, .25, .95};
    Color light = {.9, .9, .9};

    scene.num_triangles = 32;
    scene.triangles = malloc(scene.num_triangles * sizeof(Triangle));

    // Right Wall
    scene.triangles[0] = createTriangle(green, createVector(0.0, 0.0, 559.2), createVector(0.0, 0.0, 0.0), createVector(0.0, 548.8, 0.0));
    scene.triangles[1] = createTriangle(green, createVector(0.0, 0.0, 559.2), createVector(0.0, 548.8, 0.0), createVector(0.0, 548.8, 559.2));

    // Floor
    scene.triangles[2] = createTriangle(white, createVector(556.0, 0.0, 0.0), createVector(0.0, 0.0, 0.0), createVector(0.0, 0.0, 559.2));
    scene.triangles[3] = createTriangle(white, createVector(556.0, 0.0, 0.0), createVector(0.0, 0.0, 559.2), createVector(556.0, 0.0, 559.2));

    // Left Wall
    scene.triangles[4] = createTriangle(red, createVector(556.0, 0.0, 0.0), createVector(556.0, 0.0, 559.2), createVector(556.0, 548.8, 559.2));
    scene.triangles[5] = createTriangle(red, createVector(556.0, 0.0, 0.0), createVector(556.0, 548.8, 559.2), createVector(556.0, 548.8, 0.0));

    // Ceiling
    scene.triangles[6] = createTriangle(white, createVector(556.0, 548.8, 0.0), createVector(0.0, 548.8, 0.0), createVector(0.0, 548.8, 559.2));
    scene.triangles[7] = createTriangle(white, createVector(556.0, 548.8, 0.0), createVector(0.0, 548.8, 559.2), createVector(556.0, 548.8, 559.2));

    // Backwall
    scene.triangles[8] = createTriangle(white, createVector(556.0, 0.0, 559.2), createVector(0.0, 0.0, 559.2), createVector(0.0, 548.8, 559.2));
    scene.triangles[9] = createTriangle(white, createVector(556.0, 0.0, 559.2), createVector(0.0, 548.8, 559.2), createVector(556.0, 548.8, 559.2));

    // Short Block
    scene.triangles[10] = createTriangle(blue, createVector(130.0, 165.0, 65.0), createVector(82.0, 165.0, 225.0), createVector(240.0, 165.0, 272.0));
    scene.triangles[11] = createTriangle(blue, createVector(130.0, 165.0, 65.0), createVector(240.0, 165.0, 272.0), createVector(290.0, 165.0, 114.0));
    scene.triangles[12] = createTriangle(blue, createVector(290.0, 0.0, 114.0), createVector(290.0, 165.0, 114.0), createVector(240.0, 165.0, 272.0));
    scene.triangles[13] = createTriangle(blue, createVector(290.0, 0.0, 114.0), createVector(240.0, 165.0, 272.0), createVector(240.0, 0.0, 272.0));
    scene.triangles[14] = createTriangle(blue, createVector(130.0, 0.0, 65.0), createVector(130.0, 165.0, 65.0), createVector(290.0, 165.0, 114.0));
    scene.triangles[15] = createTriangle(blue, createVector(130.0, 0.0, 65.0), createVector(290.0, 165.0, 114.0), createVector(290.0, 0.0, 114.0));
    scene.triangles[16] = createTriangle(blue, createVector(82.0, 0.0, 225.0), createVector(82.0, 165.0, 225.0), createVector(130.0, 165.0, 65.0));
    scene.triangles[17] = createTriangle(blue, createVector(82.0, 0.0, 225.0), createVector(130.0, 165.0, 65.0), createVector(130.0, 0.0, 65.0));
    scene.triangles[18] = createTriangle(blue, createVector(240.0, 0.0, 272.0), createVector(240.0, 165.0, 272.0), createVector(82.0, 165.0, 225.0));
    scene.triangles[19] = createTriangle(blue, createVector(240.0, 0.0, 272.0), createVector(82.0, 165.0, 225.0), createVector(82.0, 0.0, 225.0));

    // Tall Block
    scene.triangles[20] = createTriangle(blue, createVector(423.0, 330.0, 247.0), createVector(265.0, 330.0, 296.0), createVector(314.0, 330.0, 456.0));
    scene.triangles[21] = createTriangle(blue, createVector(423.0, 330.0, 247.0), createVector(314.0, 330.0, 456.0), createVector(472.0, 330.0, 406.0));
    scene.triangles[22] = createTriangle(blue, createVector(423.0, 0.0, 247.0), createVector(423.0, 330.0, 247.0), createVector(472.0, 330.0, 406.0));
    scene.triangles[23] = createTriangle(blue, createVector(423.0, 0.0, 247.0), createVector(472.0, 330.0, 406.0), createVector(472.0, 0.0, 406.0));
    scene.triangles[24] = createTriangle(blue, createVector(472.0, 0.0, 406.0), createVector(472.0, 330.0, 406.0), createVector(314.0, 330.0, 456.0));
    scene.triangles[25] = createTriangle(blue, createVector(472.0, 0.0, 406.0), createVector(314.0, 330.0, 456.0), createVector(314.0, 0.0, 456.0));
    scene.triangles[26] = createTriangle(blue, createVector(314.0, 0.0, 456.0), createVector(314.0, 330.0, 456.0), createVector(256.0, 330.0, 296.0));
    scene.triangles[27] = createTriangle(blue, createVector(314.0, 0.0, 456.0), createVector(256.0, 330.0, 296.0), createVector(256.0, 0.0, 296.0));
    scene.triangles[28] = createTriangle(blue, createVector(265.0, 0.0, 296.0), createVector(256.0, 330.0, 296.0), createVector(423.0, 330.0, 247.0));
    scene.triangles[29] = createTriangle(blue, createVector(265.0, 0.0, 296.0), createVector(423.0, 330.0, 247.0), createVector(423.0, 0.0, 247.0));

    // Area Light
    scene.triangles[30] = createTriangle(light, createVector(343.0, 548.8, 227.0), createVector(343.0, 548.8, 332.0), createVector(213.0, 548.8, 332.0));
    scene.triangles[31] = createTriangle(light, createVector(343.0, 548.8, 227.0), createVector(213.0, 548.8, 332.0), createVector(213.0, 548.8, 227.0));

    scene.num_lights = 2;
    scene.lights = malloc(scene.num_lights * sizeof(Triangle));
    scene.lights[0] = scene.triangles[30];
    scene.lights[1] = scene.triangles[31];

    return scene;
}

void renderScene(Scene* scene){
	Color result;
	HitRecord record = createHitRecord();

    Color black = {0, 0, 0};

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
                hitTriangle(&scene->triangles[k], &record, &ray);
        	}

            if(record.has_hit){
                //record.triangle.material.shade();
                result = record.triangle->color;
            }


			setImageColor(&scene->image, i, j, result);
		}
	}
}
