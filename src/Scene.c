#include "Scene.h"

Scene createScene(char* filename){
    Scene scene = {};
    scene.max_depth = 10;
    scene.num_samples = 16;

    scene.image = createImage(500, 500);

    Vector position = {278, 273, -800};
    Vector look_at = {278, 273, 0};
    Vector up = {0, 1, 0};
    scene.camera = createCamera(position, look_at, up, 39, (float)(scene.image.width/scene.image.height));

    scene.num_materials = 4;
    scene.materials = malloc(scene.num_materials * sizeof(Material));

    scene.materials[0] = createMaterial(createColor(.95, .25, .25), .6, .4);
    scene.materials[1] = createMaterial(createColor(.25, .95, .25), .6, .4);
    scene.materials[2] = createMaterial(createColor(.95, .95, .85), .6, .4);
    scene.materials[3] = createMaterial(createColor(.9, .9, .9), .6, .4);

    scene.num_triangles = 30;
    scene.triangles = malloc(scene.num_triangles * sizeof(Triangle));

    // Right Wall
    scene.triangles[0] = createTriangle(&scene.materials[1], createVector(0.0, 0.0, 559.2), createVector(0.0, 0.0, 0.0), createVector(0.0, 548.8, 0.0));
    scene.triangles[1] = createTriangle(&scene.materials[1], createVector(0.0, 0.0, 559.2), createVector(0.0, 548.8, 0.0), createVector(0.0, 548.8, 559.2));

    // Floor
    scene.triangles[2] = createTriangle(&scene.materials[2], createVector(556.0, 0.0, 0.0), createVector(0.0, 0.0, 0.0), createVector(0.0, 0.0, 559.2));
    scene.triangles[3] = createTriangle(&scene.materials[2], createVector(556.0, 0.0, 0.0), createVector(0.0, 0.0, 559.2), createVector(556.0, 0.0, 559.2));

    // Left Wall
    scene.triangles[4] = createTriangle(&scene.materials[0], createVector(556.0, 0.0, 0.0), createVector(556.0, 0.0, 559.2), createVector(556.0, 548.8, 559.2));
    scene.triangles[5] = createTriangle(&scene.materials[0], createVector(556.0, 0.0, 0.0), createVector(556.0, 548.8, 559.2), createVector(556.0, 548.8, 0.0));

    // Ceiling
    scene.triangles[6] = createTriangle(&scene.materials[2], createVector(556.0, 548.8, 0.0), createVector(0.0, 548.8, 0.0), createVector(0.0, 548.8, 559.2));
    scene.triangles[7] = createTriangle(&scene.materials[2], createVector(556.0, 548.8, 0.0), createVector(0.0, 548.8, 559.2), createVector(556.0, 548.8, 559.2));

    // Backwall
    scene.triangles[8] = createTriangle(&scene.materials[2], createVector(556.0, 0.0, 559.2), createVector(0.0, 0.0, 559.2), createVector(0.0, 548.8, 559.2));
    scene.triangles[9] = createTriangle(&scene.materials[2], createVector(556.0, 0.0, 559.2), createVector(0.0, 548.8, 559.2), createVector(556.0, 548.8, 559.2));

    // Short Block
    scene.triangles[10] = createTriangle(&scene.materials[2], createVector(130.0, 165.0, 65.0), createVector(82.0, 165.0, 225.0), createVector(240.0, 165.0, 272.0));
    scene.triangles[11] = createTriangle(&scene.materials[2], createVector(130.0, 165.0, 65.0), createVector(240.0, 165.0, 272.0), createVector(290.0, 165.0, 114.0));
    scene.triangles[12] = createTriangle(&scene.materials[2], createVector(290.0, 0.0, 114.0), createVector(290.0, 165.0, 114.0), createVector(240.0, 165.0, 272.0));
    scene.triangles[13] = createTriangle(&scene.materials[2], createVector(290.0, 0.0, 114.0), createVector(240.0, 165.0, 272.0), createVector(240.0, 0.0, 272.0));
    scene.triangles[14] = createTriangle(&scene.materials[2], createVector(130.0, 0.0, 65.0), createVector(130.0, 165.0, 65.0), createVector(290.0, 165.0, 114.0));
    scene.triangles[15] = createTriangle(&scene.materials[2], createVector(130.0, 0.0, 65.0), createVector(290.0, 165.0, 114.0), createVector(290.0, 0.0, 114.0));
    scene.triangles[16] = createTriangle(&scene.materials[2], createVector(82.0, 0.0, 225.0), createVector(82.0, 165.0, 225.0), createVector(130.0, 165.0, 65.0));
    scene.triangles[17] = createTriangle(&scene.materials[2], createVector(82.0, 0.0, 225.0), createVector(130.0, 165.0, 65.0), createVector(130.0, 0.0, 65.0));
    scene.triangles[18] = createTriangle(&scene.materials[2], createVector(240.0, 0.0, 272.0), createVector(240.0, 165.0, 272.0), createVector(82.0, 165.0, 225.0));
    scene.triangles[19] = createTriangle(&scene.materials[2], createVector(240.0, 0.0, 272.0), createVector(82.0, 165.0, 225.0), createVector(82.0, 0.0, 225.0));

    // Tall Block
    scene.triangles[20] = createTriangle(&scene.materials[2], createVector(423.0, 330.0, 247.0), createVector(265.0, 330.0, 296.0), createVector(314.0, 330.0, 456.0));
    scene.triangles[21] = createTriangle(&scene.materials[2], createVector(423.0, 330.0, 247.0), createVector(314.0, 330.0, 456.0), createVector(472.0, 330.0, 406.0));
    scene.triangles[22] = createTriangle(&scene.materials[2], createVector(423.0, 0.0, 247.0), createVector(423.0, 330.0, 247.0), createVector(472.0, 330.0, 406.0));
    scene.triangles[23] = createTriangle(&scene.materials[2], createVector(423.0, 0.0, 247.0), createVector(472.0, 330.0, 406.0), createVector(472.0, 0.0, 406.0));
    scene.triangles[24] = createTriangle(&scene.materials[2], createVector(472.0, 0.0, 406.0), createVector(472.0, 330.0, 406.0), createVector(314.0, 330.0, 456.0));
    scene.triangles[25] = createTriangle(&scene.materials[2], createVector(472.0, 0.0, 406.0), createVector(314.0, 330.0, 456.0), createVector(314.0, 0.0, 456.0));
    scene.triangles[26] = createTriangle(&scene.materials[2], createVector(314.0, 0.0, 456.0), createVector(314.0, 330.0, 456.0), createVector(256.0, 330.0, 296.0));
    scene.triangles[27] = createTriangle(&scene.materials[2], createVector(314.0, 0.0, 456.0), createVector(256.0, 330.0, 296.0), createVector(256.0, 0.0, 296.0));
    scene.triangles[28] = createTriangle(&scene.materials[2], createVector(265.0, 0.0, 296.0), createVector(256.0, 330.0, 296.0), createVector(423.0, 330.0, 247.0));
    scene.triangles[29] = createTriangle(&scene.materials[2], createVector(265.0, 0.0, 296.0), createVector(423.0, 330.0, 247.0), createVector(423.0, 0.0, 247.0));

    scene.num_lights = 2;
    scene.lights = malloc(scene.num_lights * sizeof(Triangle));
    scene.lights[0] = createTriangle(&scene.materials[3], createVector(343.0, 548.7, 227.0), createVector(343.0, 548.7, 332.0), createVector(213.0, 548.7, 332.0));
    scene.lights[1] = createTriangle(&scene.materials[3], createVector(343.0, 548.7, 227.0), createVector(213.0, 548.7, 332.0), createVector(213.0, 548.7, 227.0));

    return scene;
}

void destroyScene(Scene* scene){
    free(scene->triangles);
    free(scene->lights);
    destroyImage(&scene->image);
    free(scene->materials);
}

void renderScene(Scene* scene){
	Color result;
	HitRecord record = createHitRecord();
    Sample sample = createSample(scene->num_samples);

    Color black = {0, 0, 0};

    int xres = scene->image.width;
    int yres = scene->image.height;

	for(int i = 0; i < xres; i++){
		for(int j = 0; j < yres; j++){

            getSamples(&sample);

            result = black;

            for(int k = 0; k < scene->num_samples; k++){
                double x = 2 * (i - xres/2. + sample.samples[k].x)/xres;
                double y = 2 * (j - yres/2. + sample.samples[k].y)/yres;

                Ray ray = cameraCreateRay(&scene->camera, x, -y);
                resetHitRecord(&record);

                for(int k = 0; k < scene->num_triangles; k++){
                    hitTriangle(&scene->triangles[k], &record, ray);
                }

                if(record.has_hit){
                    result = addColors(result, shadeWithMaterial(scene, &record, ray));
                }
            }

            result = multiplyColorByNumber(result, 1.0 / (double)scene->num_samples);

			setImageColor(&scene->image, i, j, result);
		}
	}
}
