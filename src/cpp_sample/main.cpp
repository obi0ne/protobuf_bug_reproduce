#include <Windows.h>
#include <iostream>
#include <fstream>
#include "test.pb.h"

int main(int argc, char* argv[])
{
	auto obj = std::make_shared<test_me::State_Data>();
	obj->add_myvector(1.0f);
	obj->add_myvector(1.0f);
	obj->add_myvector(1.0f);
	obj->add_myvector(1.0f);
		
	std::string buf = obj->SerializeAsString();

	auto myVec = obj->myvector();
	auto comp1 = myVec[0];
	auto comp2 = myVec[1];
	auto comp3 = myVec[2];
	auto comp4 = myVec[3];


	size_t buf_size = buf.size();
	std::ofstream outfile("serialized_state_obj.bin", std::ofstream::binary);
	outfile.write((char*)&buf_size, sizeof(buf_size));
	outfile.write(&buf[0], buf_size);
	outfile.close();

	return 0;
}