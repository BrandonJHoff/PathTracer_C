APP_NAME   = render
C_FLAGS  = -c

$(APP_NAME): Camera.o Color.o HitRecord.o Image.o main.o Material.o Ray.o Scene.o Triangle.o Vector.o
	gcc Camera.o Color.o HitRecord.o Image.o main.o Material.o Ray.o Scene.o Triangle.o Vector.o -o $(APP_NAME)

Camera.o: src/Camera.c
	gcc $(C_FLAGS) src/Camera.c

Color.o: src/Color.c
	gcc $(C_FLAGS) src/Color.c

HitRecord.o: src/HitRecord.c
	gcc $(C_FLAGS) src/HitRecord.c

Image.o: src/Image.c
	gcc $(C_FLAGS) src/Image.c

main.o: main.c
	gcc $(C_FLAGS) main.c

Material.o: src/Material.c
	gcc $(C_FLAGS) src/Material.c

Ray.o: src/Ray.c
	gcc $(C_FLAGS) src/Ray.c

Scene.o: src/Scene.c
	gcc $(C_FLAGS) src/Scene.c

Triangle.o: src/Triangle.c
	gcc $(C_FLAGS) src/Triangle.c

Vector.o: src/Vector.c
	gcc $(C_FLAGS) src/Vector.c

explain:
	@echo "APP_NAME   == $(APP_NAME)"
	@echo "CPP_FLAGS  == $(CPP_FLAGS)"

clean:
	rm -f $(APP_NAME)
	rm -f *.o
