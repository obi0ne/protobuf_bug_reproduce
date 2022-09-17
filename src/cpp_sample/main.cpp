#include <Windows.h>
#include <iostream>
#include <fstream>
#include "test.pb.h"

#define DEBUG_CPP_TO_CSHARP

int main(int argc, char* argv[])
{

	// Test C++ -> C# .NET direction
#ifdef DEBUG_CPP_TO_CSHARP
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
	std::ofstream outfile("cpp_to_csharp_serialized_state_obj.bin", std::ofstream::binary);
	outfile.write(&buf[0], buf_size);
	outfile.close();

#else

	// Test C# .NET -> C++ direction
	std::ifstream infile("csharp_to_cpp_serialized_state_obj.bin", std::ofstream::binary);
	infile.seekg(0, std::ios::end);
	auto fileSize = infile.tellg();
	infile.seekg(0, std::ios::beg);
	
	std::vector<BYTE> fileData(fileSize);
	infile.read((char*)&fileData[0], fileSize);
	infile.close();

	test_me::State_Data newObj;
	auto res = newObj.ParseFromArray((char*)&fileData[0], fileSize);

	auto myNewVector = newObj.myvector();
	auto new_comp1 = myNewVector[0];
	auto new_comp2 = myNewVector[1];
	auto new_comp3 = myNewVector[2];
	auto new_comp4 = myNewVector[3];


#endif

	return 0;
}