//
// Created by Aissam Abouqassime-Eledrissi on 1/13/25.
//

#pragma once
#include <iostream>

class Data {
	private:
		int data;
	public:
		Data();
		Data(int data);
		~Data();
		Data(const Data &data);
		Data &operator=(const Data &data);
		int	getData() const;
};
