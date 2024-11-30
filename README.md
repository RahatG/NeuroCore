Get-ChildItem -Recurse -Include *.cpp,*.h | ForEach-Object { Get-Content $_.FullName | Add-Content combined_code.txt }


Get-ChildItem -Recurse -Include *.py | ForEach-Object { Get-Content $_.FullName | Add-Content combined_code.txt }


docker stop neurocore
docker rm neurocore

docker build --no-cache -t neurocore:latest .

docker run -d -p 8000:8000 --name neurocore neurocore:latest

docker logs neurocore


export VCPKG_ROOT=/vcpkg
export TOOLCHAIN_FILE=/vcpkg/scripts/buildsystems/vcpkg.cmake


a. Clean Previous Builds
cd /home/rahat/NeuroCore/cpp_backend/build
rm -rf *
b. Run CMake with the Correct Toolchain File
cmake .. -DCMAKE_TOOLCHAIN_FILE=/home/rahat/vcpkg/scripts/buildsystems/vcpkg.cmake
c. Build the Project
make -j$(nproc)


docker exec -it neurocore /bin/bash
echo $PYTHONPATH
