import bpy

for i in range(20):
    bpy.context.scene.layers[i] = True

for ob in bpy.data.objects:
    ob.select = True
    print(ob.name, ob.select)

for ob in bpy.data.objects:
    print(ob.name, ob.select)

bpy.data.objects["Tree_1"].select = False
bpy.data.objects["Tree_2"].select = True

for ob in bpy.data.objects:
    print(ob.name, ob.select)

bpy.ops.object.select_pattern(pattern="Leaf")

# bpy.ops.export_scene.obj(
        # filepath = "./foo.obj",
        # use_selection = True)

print("selected", bpy.context.selected_objects)
