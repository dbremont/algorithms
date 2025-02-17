#include <stdio.h>
#include <math.h>

#define WIDTH  800  // Image width
#define HEIGHT 600  // Image height
#define FOV    90   // Field of view

// Structure to represent a 3D vector
typedef struct {
    double x, y, z;
} Vec3;

// Vector operations
Vec3 vec_sub(Vec3 a, Vec3 b) { return (Vec3){a.x - b.x, a.y - b.y, a.z - b.z}; }
Vec3 vec_add(Vec3 a, Vec3 b) { return (Vec3){a.x + b.x, a.y + b.y, a.z + b.z}; }
Vec3 vec_mul(Vec3 a, double b) { return (Vec3){a.x * b, a.y * b, a.z * b}; }
double vec_dot(Vec3 a, Vec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
Vec3 vec_norm(Vec3 v) { double len = sqrt(vec_dot(v, v)); return vec_mul(v, 1.0 / len); }

// Sphere structure
typedef struct {
    Vec3 center;
    double radius;
} Sphere;

// Ray-sphere intersection (returns distance or -1 if no hit)
double sphere_intersect(Sphere sphere, Vec3 origin, Vec3 dir) {
    Vec3 oc = vec_sub(origin, sphere.center);
    double b = 2.0 * vec_dot(oc, dir);
    double c = vec_dot(oc, oc) - sphere.radius * sphere.radius;
    double discriminant = b * b - 4 * c;

    if (discriminant < 0) return -1;
    return (-b - sqrt(discriminant)) / 2.0;
}

// Main ray tracing function
void render() {
    FILE *f = fopen("output.ppm", "w");
    fprintf(f, "P3\n%d %d\n255\n", WIDTH, HEIGHT);

    Vec3 camera = {0, 0, 0};
    Sphere sphere = {{0, 0, -5}, 1}; // Sphere at (0,0,-5) with radius 1
    Vec3 light = {1, 1, -2}; // Light position

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Convert pixel to normalized device coordinates
            double nx = (2 * (x + 0.5) / WIDTH - 1) * tan(FOV / 2.0 * M_PI / 180) * WIDTH / HEIGHT;
            double ny = (1 - 2 * (y + 0.5) / HEIGHT) * tan(FOV / 2.0 * M_PI / 180);
            Vec3 dir = vec_norm((Vec3){nx, ny, -1});

            double t = sphere_intersect(sphere, camera, dir);
            if (t > 0) {
                // Compute surface normal and lighting
                Vec3 hit_point = vec_add(camera, vec_mul(dir, t));
                Vec3 normal = vec_norm(vec_sub(hit_point, sphere.center));
                Vec3 light_dir = vec_norm(vec_sub(light, hit_point));
                double intensity = fmax(0, vec_dot(normal, light_dir));

                int color = (int)(255 * intensity);
                fprintf(f, "%d %d %d ", color, color, color); // Grayscale shading
            } else {
                fprintf(f, "0 0 0 "); // Background color (black)
            }
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

int main() {
    render();
    printf("Rendered output.ppm\n");
    return 0;
}
