clc
clear

% Converts the stl file into a point cloud
stlData = stlread("Aorta v14.stl");
points = stlData.Points;

patchStruct.Vertices = stlData.Points;
patchStruct.Faces = stlData.ConnectivityList;
patchStruct.FaceColor = 'r';
patch(patchStruct)
view(3)

% Matlab representation of point cloud
pcshow(points);
%pcshow(patch);


% Outputs point cloud in .txt file
%fileID = fopen('PointCloud.txt', 'w');
%fprintf(fileID,'%.5 %.5 %.5\n', points);
%fclose(fileID); 