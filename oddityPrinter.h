#pragma once

// Functor that prints 'odd' or 'even' being given an int.
struct oddityPrinter
{
public:
	void operator()(int) const;
};
