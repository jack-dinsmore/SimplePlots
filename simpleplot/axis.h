#pragma once
#include "standard.h"
#include "colors.h"
#include <string>
#include <windows.h>


namespace SimplePlot {
	class Axis {
	public:
		Axis(std::string label = "", bool logarithmic = false, SimplePlot::Color::Color backColor = SimplePlot::Color::Color::WHITE,
			SimplePlot::Color::Color color = SimplePlot::Color::Color::BLACK);
		Axis(std::string label, float maxT, float minT, bool logarithmic = false, SimplePlot::Color::Color backColor = SimplePlot::Color::Color::WHITE,
			SimplePlot::Color::Color color = SimplePlot::Color::Color::BLACK);
		~Axis();

		bool setEnds(float minT_, float maxT_);
		int getClearance();
		void drawGrid(HDC hdc, POINT origin, POINT axisEnd, POINT gridEnd);
		void drawAxis(HDC hdc, POINT origin, POINT axisEnd, POINT gridEnd);

		bool grid = true;

	private:
		void setMajorMinor();
		void makePen();

		bool logarithmic = false;
		bool fixEnds;
		float maxT;
		float minT;
		float major;
		float minor;
		std::wstring label;
		SimplePlot::Color::Color color;
		SimplePlot::Color::Color backColor;
		HPEN thickPen, thinPen, backPen;

		HFONT labelFont;
		HFONT tickFont;
	};
}