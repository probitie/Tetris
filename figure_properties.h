#pragma once



/**
* each value of the enum is an index of
* a corresponding brick texture in
* bricks texture (the image)
*/ 
enum class FigureColor
{
	darkBlue,
	violet,
	red,
	green,
	yellow,
	lightBlue,
	orange,
	blue,
	_size
};

/**
* tetramino form
*/
enum class FigureForm
{
	I,
	S,
	Z,
	T,
	L,
	J,
	O,
	_size
};
