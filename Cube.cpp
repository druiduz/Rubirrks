
/*Cube::Cube(){
    f32 cubeSize = 20.f;
    video::SColor cubeColour(255, 255, 255, 255);

    SMeshBuffer * buffer = new SMeshBuffer();
    SMeshBuffer * buffer2 = new SMeshBuffer();
    u16 u[6] = {0,2,1, 0,3,2};
    u16 u2[6] = {0,11,10, 0,10,7};

    for(s32 i = 0; i < 6; ++i){
        buffer->Indices.push_back(u[i]);
        buffer2->Indices.push_back(u2[i]);
    }

    // set material per buffer, use this or the one at the end of this code
    buffer->Material.Textures[0] = texture1;
    buffer2->Material.Textures[0] = texture2;

    buffer->Vertices.set_used(12);
    buffer->Vertices[0] = video::S3DVertex(0,0,0, -1,-1,-1, cubeColour, 0, 1);
    buffer->Vertices[1] = video::S3DVertex(1,0,0, 1,-1,-1, cubeColour, 1, 1);
    buffer->Vertices[2] = video::S3DVertex(1,1,0, 1, 1,-1, cubeColour, 1, 0);
    buffer->Vertices[3] = video::S3DVertex(0,1,0, -1, 1,-1, cubeColour, 0, 0);
    buffer->Vertices[4] = video::S3DVertex(1,0,1, 1,-1, 1, cubeColour, 0, 1);
    buffer->Vertices[5] = video::S3DVertex(1,1,1, 1, 1, 1, cubeColour, 0, 0);

    buffer2->Vertices[0] = video::S3DVertex(0,1,1, -1, 1, 1, cubeColour, 1, 0);
    buffer2->Vertices[1] = video::S3DVertex(0,0,1, -1,-1, 1, cubeColour, 1, 1);
    buffer2->Vertices[2] = video::S3DVertex(0,1,1, -1, 1, 1, cubeColour, 0, 1);
    buffer2->Vertices[3] = video::S3DVertex(0,1,0, -1, 1,-1, cubeColour, 1, 1);
    buffer2->Vertices[4] = video::S3DVertex(1,0,1, 1,-1, 1, cubeColour, 1, 0);
    buffer2->Vertices[5] = video::S3DVertex(1,0,0, 1,-1,-1, cubeColour, 0, 0);


    buffer->BoundingBox.reset(0,0,0);
    // ......

    SMesh * cubeMesh = new SMesh();
    cubeMesh->addMeshBuffer(buffer);
    cubeMesh->addMeshBuffer(buffer2);

    ISceneNode * cubeSceneNode = smgr->addMeshSceneNode(cubeMesh);

    //Set material per scene node, material count should be the same as buffer count
    cubeSceneNode->getMaterial(0).Textures[0] = texture1;
    cubeSceneNode->getMaterial(1).Textures[0] = texture2;


}*/
