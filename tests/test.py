
import module3

# initialize engine
module3.init()
# create a mesh
_mesh = module3.addMesh()

# # just for fun
# del _mesh

# loop
while module3.isActive() :
    module3.update()
