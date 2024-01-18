#include <iostream>
#include <windows.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
		std::cout << "Usage: RemoveManifestFromDll <dll file> <resource id>" << std::endl;
		return 0;
	}

    auto handle = BeginUpdateResourceA(argv[1], FALSE);
    if (nullptr == handle)
    {
		std::cout << "Error: " << GetLastError() << std::endl;
		return 1;
	}

    auto result = UpdateResource(handle, RT_MANIFEST, MAKEINTRESOURCE(atoi(argv[2])), MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), nullptr, 0);
	if (!result) {
		std::cout << "Could not remove resource." << std::endl;
		return 1;
	}

    result = EndUpdateResource(handle, FALSE);
	if (!result) {
		std::cout << "Could not write changes." << std::endl;
		return 1;
	}

	std::cout << "Resource removed." << std::endl;
	return 0;
}

