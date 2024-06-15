#pragma once
#include <string>

struct Window
{
    explicit Window(const std::string& title = "Title", float width = 320.0f, 
        float height = 180.0f, bool isVSyncOn = true);

    std::string title;
    float width;
    float height;
    bool isVSyncOn;
};

struct Point2f
{
    Point2f();
    Point2f(float x, float y);

    float x;
    float y;
};

struct Vector2f;
struct Rectf
{
    Rectf();
    explicit Rectf(float left, float bottom, float width, float height);

    Vector2f Pos() const;
    Vector2f Size() const;
    
    float left;
    float bottom;
    float width;
    float height;

    // for lerp
    Rectf operator+(const Rectf& other);
    Rectf operator-(const Rectf& other);
    Rectf operator*(float other);
};

std::ostream& operator<< (std::ostream& lhs, const Rectf& rhs);

struct Color4f
{
    Color4f();
    Color4f(int hex);
    explicit Color4f(float r, float g, float b, float a);
    
    float r;
    float g;
    float b;
    float a;

    // for lerp
    Color4f operator+(const Color4f& other);
    Color4f operator-(const Color4f& other);
    Color4f operator*(float other);
};
std::ostream& operator<< (std::ostream& lhs, const Color4f& rhs);

struct Circlef
{
    Circlef();
    explicit Circlef(const Point2f& center, float radius);
    explicit Circlef(float centerX, float centerY, float radius);

    Point2f center;
    float radius;
};


struct Ellipsef
{
    Ellipsef();
    explicit Ellipsef(const Point2f& center, float radiusX, float radiusY);
    explicit Ellipsef(float centerX, float centerY, float radiusX, float radiusY);

    Point2f center;
    float radiusX;
    float radiusY;
};

