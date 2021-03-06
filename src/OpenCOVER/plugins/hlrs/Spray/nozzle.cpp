#include "nozzle.h"

nozzle::nozzle(osg::Matrix initialMat, float size, std::string nozzleName):
    coVR3DTransRotInteractor(initialMat,size,coInteraction::ButtonA,"Menu",nozzleName.c_str(),coInteraction::Medium)
{
    //boundingBox_ = osg::Vec3(2000,2000,2000);
    nozzleName_ = nozzleName;
    geode_ = new osg::Geode;
    geode_->setName(nozzleName);

    prevGenCreate = parser::instance()->getNewGenCreate();

    transform_ = new osg::MatrixTransform;

    float t[] = {1,0,0,0,
                 0,1,0,0,
                 0,0,1,0,
                 0,0,0,1
                };
    osg::Matrix baseTransform;
    baseTransform.set(t);
    transform_->setMatrix(baseTransform);
    //scaleTransform->setMatrix(baseTransform);

    particleCount_ = parser::instance()->getReqParticles();

    cylinder_ = new osg::Cylinder(osg::Vec3(0,0,0),10,10);                      //diameter = lenght = 10, just for rendering purpose
    cylinder_->setRotation(osg::Quat(1,0,0,1));
    shapeDrawable_ = new osg::ShapeDrawable(cylinder_);
    shapeDrawable_->setColor(osg::Vec4(1,1,0,1));
    printf("Adding basic geometry to nozzle\n");

    geode_->addDrawable(shapeDrawable_);

    createGeometry();
}

nozzle::~nozzle(){
    if(!genList.empty()){
        for(auto i = genList.begin();i != genList.end(); i++){
            class gen* current = *i;

            delete current;

        }
        genList.clear();
        printf("list cleared!\n");
    }
    printf("Bye!\n");
}

void nozzle::createGeometry(){
        osg::BoundingBox bb;
        bb = cover->getBBox(geode_);
        //transform_->addChild(scaleTransform.get());
        scaleTransform->setName("transform");
        scaleTransform->removeChild(0,scaleTransform->getNumChildren());
        //cover->getObjectsRoot()->addChild(transform_.get());
        scaleTransform->addChild(geode_);
        //scaleTransform->addChild(transform_.get());
//        transform_->removeChild(0,transform_->getNumChildren());

//        transform_->addChild(geode_);
}

void nozzle::createGen(){
    class gen* newGen = new class gen(initPressure_, this);
    newGen->setColor(getColor());

    genList.push_back(newGen);
}

void nozzle::deleteGen(class gen* current){
    if(current == genList.front()){
        printf("first item removed");
        genList.pop_front();
    }
    else if(current == genList.back()){
        printf("last item removed");
        genList.pop_back();

    }
    else{
        printf("item removed!");
        genList.remove(current);
    }
}

void nozzle::updateGen(){

    if(prevGenCreate != parser::instance()->getNewGenCreate())
    {
        prevGenCreate = parser::instance()->getNewGenCreate();
        counter = 0;
    }

    for(auto i = genList.begin();i != genList.end(); i++){
        class gen* current = *i;
        if(current->isOutOfBound() == true){
            printf("generation out of bound\n");
            delete current;
            genList.erase(i);
            i = genList.begin();
        }
        else{
            current->updatePos(boundingBox_);
        }
    }
    if(counter == parser::instance()->getNewGenCreate()){
        createGen();
        counter = 0;
        printf("New gen created\n");
    }
    counter++;
}

void nozzle::updateColor(){
    for(auto i = genList.begin();i != genList.end(); i++){
        class gen* current = *i;
        current->setColor(currentColor_);
    }
}

void nozzle::save(std::string pathName, std::string fileName){
    FILE* saving = new FILE;
    char ptr[1000];

    saving = fopen((pathName+fileName).c_str(), "a");
    fputs("\n", saving);

    fputs("name = ", saving);
    fputs(nozzleName_.c_str(), saving);
    fputs("\n", saving);

    fputs("position = \n", saving);
    osg::Matrix nozzleMatrix = this->getMatrix();

    sprintf(ptr, "%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n",  nozzleMatrix.ptr()[0],nozzleMatrix.ptr()[1],nozzleMatrix.ptr()[2],nozzleMatrix.ptr()[3],
                                                                          nozzleMatrix.ptr()[4],nozzleMatrix.ptr()[5],nozzleMatrix.ptr()[6],nozzleMatrix.ptr()[7],
                                                                          nozzleMatrix.ptr()[8],nozzleMatrix.ptr()[9],nozzleMatrix.ptr()[10],nozzleMatrix.ptr()[11],
                                                                          nozzleMatrix.ptr()[12],nozzleMatrix.ptr()[13],nozzleMatrix.ptr()[14],nozzleMatrix.ptr()[15]);

    fputs(ptr,saving);
    fputs("\n",saving);

    fputs("type = NULL\n", saving);

    fputs("\n",saving);
    fputs("-", saving);
    fclose(saving);

    printf("Nozzle configuration saved!\n");
}

void nozzle::setID(int ID)
{
    if(initialized == false)
    {
        nozzleID = ID;
        initialized = true;
    }
    else std::cout << "ID was already set" << std::endl;
}

int nozzle::getID()
{
    return nozzleID;
}

void nozzle::keepSize()
{
    osg::Matrix m;
    m.makeScale(6.0, 6.0, 6.0);
    scaleTransform->setMatrix(m);
}





standardNozzle::standardNozzle(float sprayAngle, std::string decoy, osg::Matrix initialMat, float size, std::string nozzleName) :
    nozzle(initialMat, size, nozzleName)
{
    if(sprayAngle == 0)
    {
        sprayAngle_ = 30;
    }
    else sprayAngle_ = sprayAngle;
    if(decoy.empty())
        decoy_ = "NONE";
    else decoy_ = decoy.c_str();
}

void standardNozzle::createGen(){
    class standardGen* newGen = new class standardGen(sprayAngle_, decoy_,getInitPressure(), this);
    newGen->setColor(getColor());

    genList.push_back(newGen);
}

void standardNozzle::save(std::string pathName, std::string fileName){
    FILE* saving = new FILE;
    char ptr[20];
    char matrixPtr[1000];

    saving = fopen((pathName+fileName).c_str(), "a");
    fputs("\n", saving);

    fputs("name = ", saving);
    fputs(nozzleName_.c_str(), saving);
    fputs("\n", saving);
    fputs("\n", saving);

    fputs("position = \n", saving);
    osg::Matrix nozzleMatrix = this->getMatrix();

    sprintf(matrixPtr, "%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n",  nozzleMatrix.ptr()[0],nozzleMatrix.ptr()[1],nozzleMatrix.ptr()[2],nozzleMatrix.ptr()[3],
                                                                          nozzleMatrix.ptr()[4],nozzleMatrix.ptr()[5],nozzleMatrix.ptr()[6],nozzleMatrix.ptr()[7],
                                                                          nozzleMatrix.ptr()[8],nozzleMatrix.ptr()[9],nozzleMatrix.ptr()[10],nozzleMatrix.ptr()[11],
                                                                          nozzleMatrix.ptr()[12],nozzleMatrix.ptr()[13],nozzleMatrix.ptr()[14],nozzleMatrix.ptr()[15]);

    fputs(matrixPtr,saving);
    fputs("\n",saving);

    fputs("type = standard\n", saving);
    char* returnVal = gcvt(sprayAngle_, 5,ptr);
    //fputs("\n", saving);
    fputs("angle = ", saving);
    fputs(ptr, saving);
    fputs("\n", saving);
    fputs("decoy = ", saving);
    fputs(decoy_,saving);
    fputs("\n",saving);

    fputs("\n",saving);
    fputs("-", saving);
    fclose(saving);

    printf("Nozzle configuration saved!\n");
}




imageNozzle::imageNozzle(std::string pathName, std::string fileName, osg::Matrix initialMat, float size, std::string nozzleName):
    nozzle(initialMat, size, nozzleName)
{
    if(fileName.empty())fileName_ = "Nozzle_1000_4_1_2.bmp";
    else fileName_ = fileName;
    pathName_ = pathName;

    samplingPoints = particleCount_;
    colorThreshold_ = parser::instance()->getColorThreshold();

    if(parser::instance()->getSamplingType().compare("circle") == 0)
    {
        circle = true;
        square = false;
    }

    if(parser::instance()->getSamplingType().compare("square") == 0)
    {
        circle = false;
        square = true;
    }

    if(readImage() == false)
    {
        delete this;
        failed = true;
    }
}

imageNozzle::~imageNozzle()
{
    //delete iBuf.dataBuffer;
}

void imageNozzle::createGen(){
    class imageGen* newGen = new class imageGen(&iBuf,getInitPressure(), this);
    newGen->setColor(getColor());

    genList.push_back(newGen);
}

void imageNozzle::save(std::string pathName, std::string fileName){
    FILE* saving = new FILE;
    char matrixPtr[1000];

    saving = fopen((pathName+fileName).c_str(), "a");
    fputs("\n", saving);

    fputs("name = ", saving);
    fputs(nozzleName_.c_str(), saving);
    fputs("\n", saving);

    fputs("position = \n", saving);
    osg::Matrix nozzleMatrix = this->getMatrix();

    sprintf(matrixPtr, "%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n%f %f %f %f\n",  nozzleMatrix.ptr()[0],nozzleMatrix.ptr()[1],nozzleMatrix.ptr()[2],nozzleMatrix.ptr()[3],
                                                                          nozzleMatrix.ptr()[4],nozzleMatrix.ptr()[5],nozzleMatrix.ptr()[6],nozzleMatrix.ptr()[7],
                                                                          nozzleMatrix.ptr()[8],nozzleMatrix.ptr()[9],nozzleMatrix.ptr()[10],nozzleMatrix.ptr()[11],
                                                                          nozzleMatrix.ptr()[12],nozzleMatrix.ptr()[13],nozzleMatrix.ptr()[14],nozzleMatrix.ptr()[15]);

    fputs(matrixPtr,saving);
    fputs("\n",saving);

    fputs("type = image\n", saving);
    fputs("pathname = ", saving);
    fputs(pathName_.c_str(), saving);
    fputs("\n", saving);
    fputs("filename = ", saving);
    fputs(fileName_.c_str(), saving);
    fputs("\n", saving);

    fputs("\n",saving);
    fputs("-", saving);

    fclose(saving);

    printf("Nozzle configuration saved!\n");
}

bool imageNozzle::readImage()
{
    osg::Image* image = osgDB::readImageFile(fileName_);

    if(image == NULL)
    {
        std::cout << "Image wasn't readable" << std::endl;
        return false;
    }

    int* points_(new int[samplingPoints]);

    int corner_points[] = {0,0,0,0};
    /**********************************************************************************/
    //Testweise erstellt zum Einlesen von Namen

    std::string line;

    std::stringstream nameStream(fileName_);

    std::getline(nameStream, line, '_');                        //Name of the nozzle
    std::cout << line << std::endl;

    std::getline(nameStream, line, '_');
    float height = stof(line)/10;

    std::getline(nameStream, line, '_');
    pixel_to_mm_ = stof(line);

    std::getline(nameStream, line, '_');
    pixel_to_flow_ = stof(line);

    std::getline(nameStream, line, '.');
    pixel_to_radius_ = stof(line)*0.001;

    std::cout << height << " " << pixel_to_mm_ << " " << pixel_to_flow_ << " " << pixel_to_radius_ << std::endl;

    /**********************************************************************************/


    if(image->isDataContiguous())printf("Data is contiguous\n");
    else printf("Data is not contiguous!\n");

    int colorDepth = image->getTotalDataSize()/(image->s()*image->t());
    colorDepth_ = colorDepth;
    int s_int = image->s()*colorDepth;
    int t_int = image->t()*colorDepth;

    int center = (image->s()*0.5*image->t()+image->s()*0.5)*colorDepth;
    int center_width = (center%s_int)/colorDepth;
    int center_height = (center-center_width)/t_int;

    int point_width = 0;
    int point_height = 0;

    /***********************************************************************************************/
    //Defines corner points of the read image

#if square
    std::cout << "square" << std::endl;
    for(int i = 0; i<4;i++){
        int random_point = 0;
        if(i == 0){
            random_point = center-0.4*s_int;
            int count = 3;
            while(image->data()[random_point]<colorThreshold_){
                random_point = center-image->s()*0.4+count;
                count+=3;
            }
        }
        if(i == 1){
            random_point = center+0.4*s_int;
            int count = 3;
            while(image->data()[random_point]<colorThreshold_){
                random_point = center+image->s()*0.4-count;
                count+=3;
            }
        }
        if(i == 2){
            random_point = 1.4*s_int;
            while(image->data()[random_point]<colorThreshold_){
                random_point += image->s();
            }
        }
        if(i == 3){
            random_point = image->getTotalDataSize()-image->s()*1.4;
            while(image->data()[random_point]<colorThreshold_){
                random_point -= image->s();
            }
        }
        corner_points[i] = random_point;

    }

    int delta_1 = abs(center-corner_points[0]);
    int delta_2 = abs(center-corner_points[1]);
    int delta_3 = abs(center-corner_points[2]);
    int delta_4 = abs(center-corner_points[3]);

    if(delta_3>delta_4){
        corner_points[3] = center+delta_3;
    }
    else corner_points[2] = center-delta_4;

    if(delta_1>delta_2){
        corner_points[0] = corner_points[2]-delta_1;
        corner_points[1] = corner_points[2]+delta_1;
        corner_points[2] = corner_points[3]-delta_1;
        corner_points[3] += delta_1;
    }
    else{
        corner_points[0] = corner_points[2]-delta_2;
        corner_points[1] = corner_points[2]+delta_2;
        corner_points[2] = corner_points[3]-delta_2;
        corner_points[3] += delta_2;
    }

    delta_1 = corner_points[1]-corner_points[0];
    delta_2 = (corner_points[2]-corner_points[0])/t_int;
#endif

    int count = 0;

    /***********************************************************************************************/
    //Based on the amount of samplings, specific points are chosen from the relevant area

#if square

    int ppl = samplingPoints/(delta_2);
    int steppingPerLine = delta_1/(ppl-2+1);

    std::cout << ppl << " " <<steppingPerLine << std::endl;

    for(int i = 0; i<delta_2; i++){

        for(int j = 0; j < ppl;j++){
            if(j == ppl-1) points_[count] = corner_points[0]+delta_2+s_int*i;
            else points_[count] = corner_points[0]+steppingPerLine*j+s_int*i;
            if(image->data()[points_[count]] > colorThreshold_)count++;
        }
    }

    samplingPoints = count;
    std::cout << count << std::endl;

    count = 0;

#endif

#if circle
    std::cout << "circle" << std::endl;

    int nrOfCircles = 15;
    int samplingRadius = getMin(s_int*0.5,t_int*0.5);

    float div = 0;
    for(int i = 0;i<nrOfCircles;i++)
    {
        div += ((float)nrOfCircles-i)/(float)nrOfCircles;
    }

    float nBegin = samplingPoints/div;

    for(int j = 0; j<nrOfCircles;j++)
    {
        float curPoints = nBegin*(1-(float)j/(float)nrOfCircles);
        float curRadius = samplingRadius*(1-(float)j/(float)nrOfCircles)/colorDepth;
        float step = 360/curPoints;

        for(int i = 0; i<(int)curPoints;i++)
        {
            int x = curRadius*cos(step*i*Pi/180);
            int y = curRadius*sin(step*i*Pi/180);
            points_[count] = posToCount((center_width+x),(center_height+y),s_int);
            count++;

        }
    }

    printf("%i\n", count);
    samplingPoints = count;

    count = 0;

#endif

    int index = 0;


    /***********************************************************************************************/
    //Angles for later purpose are defined here

//    std::string newFileName;
//    if(fileName_.empty()) newFileName = "untitled.jpg.txt";
//    else newFileName = (pathName_+fileName_).append(".txt");

//    std::ofstream mystream(newFileName);

//    imageFilePath = newFileName;

//    mystream << "# Position X Center  Position Y Center" << std::endl;
//    mystream << center_width << " " << center_height << std::endl;
//    mystream << "# AngleToNozzle    AngleToPosition    PositionX    PositionY   Flow    Radius" << std::endl;
//    mystream << std::endl;

    int deltaWidth = 0;
    int deltaHeight = 0;
    float angleToNozzle = 0;
    float angleToPosition = 0;
    float particleFlow = 0;
    float particleRadius = 0;

    std::cout << "Starting to write image file to "<< "newFileName" <<std::endl;

    iBuf.centerX = center_width;
    iBuf.centerY = center_height;
    iBuf.samplingPoints = samplingPoints;
    iBuf.dataBuffer = new float[samplingPoints*6];

    for(count; count < samplingPoints; count++){

        index = points_[count];

        point_width = (index%s_int)/colorDepth;
        point_height = (index-point_width)/t_int;

        deltaWidth = point_width-center_width;         //Particle width - center +2
        deltaHeight = point_height-center_height;       //Particle height - center +3

        float hypotenuse = sqrt(pow(deltaWidth,2)+pow(deltaHeight,2));
        angleToNozzle = atan2(hypotenuse,height);

        if(deltaHeight == 0) angleToPosition = atan2(deltaWidth, 0.00000001);
        else angleToPosition = atan2(deltaWidth,deltaHeight);
                                                            //Angle between height and width of particle - center

        particleFlow = 0.25*(  image->data()[index]+
                                image->data()[index+3]+
                                image->data()[index+s_int]+
                                image->data()[index+s_int+3]
                                )*pixel_to_flow_;
                                                            //Flow

        particleRadius = image->data()[index]*pixel_to_radius_;
                                                            //Radius

        iBuf.dataBuffer[count*6] = angleToNozzle;
        iBuf.dataBuffer[count*6+1] = angleToPosition;
        iBuf.dataBuffer[count*6+2] = deltaWidth;
        iBuf.dataBuffer[count*6+3] = deltaHeight;
        iBuf.dataBuffer[count*6+4] = particleFlow;
        iBuf.dataBuffer[count*6+5] = particleRadius;

        //mystream << angleToNozzle << " " << angleToPosition << " " << deltaWidth << " " << deltaHeight << " " << particleFlow << " " << particleRadius << std::endl;

//        frequency_[count] = 3*intensity_[count]/(4*pow(radius_[count],3)*Pi);

//        min_particles += frequency_[count];




    };

    //mystream.close();


    std::cout << "Reading image completed!\n" << std::endl;

    return true;
}
