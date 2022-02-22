clc
clear

% Converts the stl file into a point cloud
stlData = stlread("AortaAssemblyv3.stl");
points = stlData.Points;


% Matlab representation of point cloud
%pcshow(points);



% Outputs point cloud in .txt file
fileID = fopen('PointCloud.txt', 'w');
fprintf(fileID,'%3.2f %3.2f %1.2f\n', points);
fclose(fileID); 