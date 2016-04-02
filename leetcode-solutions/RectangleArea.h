#pragma once

//Find the total area covered by two rectilinear rectangles in a 2D plane.
//
//Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//
//Assume that the total area is never beyond the maximum possible value of int.

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int minA = A < E ? E : A;
	int minB = B < F ? F : B;
	int maxA = C < G ? C : G;
	int maxB = D < H ? D : H;
	if (maxA < minA) maxA = minA;
	if (maxB < minB) maxB = minB;
	return (C - A)*(D - B) + (G - E)*(H - F) -
		(maxA - minA) * (maxB - minB);
}