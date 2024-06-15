#include "Engine/structs.h"
#include "Engine/Vector2f.h"
#include <string>
#include <iostream>

//-----------------------------------------------------------------
// Window Constructors
//-----------------------------------------------------------------
Window::Window(const std::string& title , float width , float height , bool isVSyncOn)
    :title{ title }
    ,width{ width }
    ,height{ height }
    ,isVSyncOn{ isVSyncOn }
{
}

//-----------------------------------------------------------------
// Point2f Constructors
//-----------------------------------------------------------------
Point2f::Point2f()
    :Point2f{ 0.0f, 0.0f }
{
}
Point2f::Point2f(float x, float y)
    :x{ x }, y{ y }
{
}

//-----------------------------------------------------------------
// Rectf Constructors
//-----------------------------------------------------------------
Rectf::Rectf()
    :Rectf{ 0.0f, 0.0f, 0.0f, 0.0f }
{
}

Rectf::Rectf(float left, float bottom, float width, float height)
    :left{ left }
    ,bottom{ bottom }
    ,width{ width }
    ,height{ height }
{
}

Vector2f Rectf::Pos() const
{
    return Vector2f{
        left, bottom
    };
}

Vector2f Rectf::Size() const
{
    return Vector2f{
        width, height
    };
}

Rectf Rectf::operator+(const Rectf& other)
{
    return Rectf{
        left + other.left,
        bottom + other.bottom,
        width + other.width,
        height + other.height
    };
}

Rectf Rectf::operator-(const Rectf& other)
{
    return Rectf{
        left - other.left,
        bottom - other.bottom,
        width - other.width,
        height - other.height
    };
}

Rectf Rectf::operator*(float other)
{
    return Rectf{
        left * other,
        bottom * other,
        width * other,
        height * other
    };
}

std::ostream& operator<< (std::ostream& lhs, const Rectf& rhs)
{
    lhs << std::to_string(rhs.left) << std::string(", ")
        << std::to_string(rhs.bottom) << std::string(", ")
        << std::to_string(rhs.width) << std::string(", ")
        << std::to_string(rhs.height);

    return lhs;
}

//-----------------------------------------------------------------
// Color4f Constructors
//-----------------------------------------------------------------
Color4f::Color4f()
    :Color4f{ 0.0f, 0.0f, 0.0f, 1.0f }
{
}

Color4f::Color4f(int hex)
    : Color4f(
        float(hex & 0xFF0000 >> 4) / 0xFF,
        float(hex & 0x00FF00 >> 2) / 0xFF,
        float(hex & 0x0000FF     ) / 0xFF, 1)
{

}

Color4f::Color4f(float r, float g, float b, float a)
    :r{ r }
    ,g{ g }
    ,b{ b }
    ,a{ a }
{
}

Color4f Color4f::operator+(const Color4f& other)
{
    return Color4f{
        r + other.g,
        g + other.g,
        b + other.b,
        a + other.a,
    };
}

Color4f Color4f::operator-(const Color4f& other)
{
    return Color4f{
        r - other.g,
        g - other.g,
        b - other.b,
        a - other.a,
    };
}

Color4f Color4f::operator*(float other)
{
    return Color4f{
        r * other,
        g * other,
        b * other,
        a * other,
    };
}

std::ostream& operator<< (std::ostream& lhs, const Color4f& rhs)
{
    lhs << std::to_string(rhs.r) << std::string(", ")
        << std::to_string(rhs.g) << std::string(", ")
        << std::to_string(rhs.b) << std::string(", ")
        << std::to_string(rhs.a);

    return lhs;
}

//-----------------------------------------------------------------
// Circlef Constructors
//-----------------------------------------------------------------
Circlef::Circlef()
    :Circlef{ 0.0f, 0.0f, 0.0f }
{
}

Circlef::Circlef(float centerX, float centerY, float radius)
    :Circlef{ Point2f{ centerX, centerY }, radius }
{
}

Circlef::Circlef(const Point2f& center, float radius)
    :center{ center }
    ,radius{ radius }
{
}

//-----------------------------------------------------------------
// Ellipsef Constructors
//-----------------------------------------------------------------
Ellipsef::Ellipsef()
    :Ellipsef{ 0.0f, 0.0f, 0.0f, 0.0f }
{
}


Ellipsef::Ellipsef(const Point2f& center, float radiusX, float radiusY)
    : center{ center }
    , radiusX{ radiusX }
    , radiusY{ radiusY }
{
}

Ellipsef::Ellipsef(float centerX, float centerY, float radiusX, float radiusY)
    : Ellipsef{ Point2f{ centerX, centerY }, radiusX, radiusY }
{
}
