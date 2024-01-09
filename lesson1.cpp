//
// Created by Иван Ильин on 23.02.2022.
//
#include <linalg/Vec2D.h>
#include <linalg/Vec3D.h>
#include <linalg/Vec4D.h>
#include <linalg/Matrix4x4.h>

int main() {
    /*
     * EN:
     * TODO: implement vectors and matrices
     * You should work with the following files:
     *
     * engine/linalg/Vec2D.cpp
     * engine/linalg/Vec3D.cpp
     * engine/linalg/Vec4D.cpp
     * engine/linalg/Matrix4x4.cpp
     *
     * If you do it right, you will see message in a terminal 'Process finished with exit code 0'
     * (You shall to run this in a Debug mode)
     *
     * RU:
     * TODO: реализуйте векторы и матрицы
     * На этом уроке вам необходимо работать со следующими файлами:
     *
     * engine/linalg/Vec2D.cpp
     * engine/linalg/Vec3D.cpp
     * engine/linalg/Vec4D.cpp
     * engine/linalg/Matrix4x4.cpp
     *
     * Если вы всё сделали правильно, то должно появится сообщение 'Process finished with exit code 0'
     * (Запускать необходимо в Debug моде)
     */

    // testing of vectors and matrices
    Vec2D::test();
    Vec3D::test();
    Vec4D::test();
    Matrix4x4::test();
}
