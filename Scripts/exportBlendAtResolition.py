import bpy
import sys
import os

try:
    os.mkdirs("Build/Obj")
except:
    False

print(bpy.data.filepath)

path = bpy.data.filepath.split('/')
filename = path[-1].replace(".blend", "")
path = path[:-1]

def outputPath(i):
    return "/".join(path + [filename + "_" + str(i - 1) + ".obj"]) 

print(outputPath(2))

for layer in range(20):
    bpy.context.scene.layers[layer] = True

for resolution in range(1, 20):
    numberOfObjs = 0
    for ob in bpy.data.objects:
        if "_" + str(resolution) in ob.name:
            ob.select = True
            numberOfObjs = numberOfObjs + 1
        else:
            ob.select = False

    if numberOfObjs == 0:
        break

    print("number", numberOfObjs, "on", resolution)

    bpy.ops.export_scene.obj(
            filepath = outputPath(resolution),
            use_selection = True)
