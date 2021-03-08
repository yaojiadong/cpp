/*
 * Compound_graphic.h
 *
 *  Created on: Mar 8, 2021
 *      Author: jiado
 */

#ifndef DESIGN_PATTERN_COMPOSITE_COMPOUND_GRAPHIC_H_
#define DESIGN_PATTERN_COMPOSITE_COMPOUND_GRAPHIC_H_

#include "IGraphic.h"
#include <vector>
#include <memory>
#include <iostream>

class Compound_graphic :public IGraphic{
public:
	virtual void move(int x, int y) override {
		for(auto g : graphics){
			g->move(x, y);
		}
	}
	virtual void draw() const override {
		std::cout << "Draw compound graphic\n";
		for(auto g : graphics){
			g->draw();
		}
	}

	void add(std::shared_ptr<IGraphic> graphic) {graphics.push_back(graphic);}
	void remove(std::shared_ptr<IGraphic> graphic) {graphics.erase(std::find(graphics.begin(), graphics.end(), graphic));}

private:
	std::vector<std::shared_ptr<IGraphic>> graphics;  //graphics stores IGraphics: dot, circle, and compound_graphic itself
};


#endif /* DESIGN_PATTERN_COMPOSITE_COMPOUND_GRAPHIC_H_ */
