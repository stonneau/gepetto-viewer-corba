//
//  GraphicalInterface.impl.hh
//  Corbaserver for SceneViewer
//
//  Created by Mathieu Geisert on November 2014.
//  Copyright (c) 2014 LAAS-CNRS. All rights reserved.
//

#ifndef SCENEVIEWER_CORBASERVER_GRAPHICALINTERFACE_HH
#define SCENEVIEWER_CORBASERVER_GRAPHICALINTERFACE_HH

#include <omniORB4/CORBA.h>

#include "gepetto/viewer/corba/server.hh"
#include "graphical-interface.hh"

namespace graphics {
namespace corbaServer {
namespace impl {

struct NodeConfiguration {
    NodePtr_t node;
    osgVector3 position;
    osgQuat quat;
};

using graphics::WindowsManagerPtr_t;
class GraphicalInterface :
    public virtual POA_gepetto::corbaserver::GraphicalInterface
{
private:
    WindowsManagerPtr_t windowsManager_;
    typedef gepetto::Error Error;
    typedef CORBA::ULong WindowID;
    typedef graphics::WindowsManager::value_type value_type;

public:
    /**
        \brief Default constructor
        */
    GraphicalInterface (corbaServer::Server* server);

  virtual void getNodeList() throw (Error);
  virtual void getWindowList() throw (Error);

  virtual bool setRate(CORBA::Long rate) throw (Error);
  virtual void refresh() throw (Error);

  virtual WindowID createWindow(const char* windowNameCorba) throw (Error);
  virtual WindowID getWindowID (const char* windowNameCorba) throw (Error);

  virtual void createScene(const char* sceneNameCorba)  throw (Error);
  virtual void createSceneWithFloor(const char* sceneNameCorba)  throw (Error);
  virtual bool addSceneToWindow(const char* sceneNameCorba, const WindowID windowId)  throw (Error);


  virtual bool addBox(const char* boxName, float boxSize1, float boxSize2, float boxSize3, const value_type* color) throw (Error);

  virtual bool addCapsule(const char* capsuleName, float radius, float height, const value_type* color) throw (Error);

  virtual bool addMesh(const char* meshNameCorba, const char* meshPathCorba)  throw (Error);

  virtual bool addCone(const char* coneName, float radius, float height, const value_type* color) throw (Error);

  virtual bool addCylinder(const char* cylinderName, float radius, float height, const value_type* color) throw (Error);

  virtual bool addSphere(const char* sphereName, float radius, const value_type* color) throw (Error);

  virtual bool addLine(const char* lineName, const value_type* pos1, const value_type* pos2, const value_type* color) throw (Error);

  virtual bool addSquareFace(const char* faceName, const value_type* pos1, const value_type* pos2, const value_type* pos3, const value_type* pos4, const value_type* color) throw (Error);
  virtual bool addTriangleFace(const char* faceName, const value_type* pos1, const value_type* pos2, const value_type* pos3, const value_type* color) throw (Error);

  virtual bool addXYZaxis (const char* nodeNameCorba, const value_type* colorCorba, float radius, float sizeAxis) throw (Error);

  virtual bool createRoadmap(const char* nameCorba,const value_type* colorNodeCorba, float radius, float sizeAxis, const value_type* colorEdgeCorba) throw(Error);

  virtual bool addEdgeToRoadmap(const char* nameRoadmap, const value_type* posFrom, const value_type* posTo) throw(Error);

  virtual bool addNodeToRoadmap(const char* nameRoadmap, const value_type* configuration) throw(Error);


  virtual bool addURDF(const char* urdfNameCorba, const char* urdfPathCorba, const char* urdfPackagePathCorba) throw (Error);

  virtual bool addUrdfCollision (const char* urdfNameCorba,
				 const char* urdfPathCorba,
				 const char* urdfPackagePathCorba)
    throw (Error);

  virtual void addUrdfObjects (const char* urdfNameCorba,
			       const char* urdfPathCorba,
			       const char* urdfPackagePathCorba,
			       bool visual)
    throw (Error);

  virtual bool createGroup(const char* groupNameCorba)  throw (Error);
  virtual bool addToGroup(const char* nodeNameCorba, const char* groupNameCorba)  throw (Error);
  virtual bool removeFromGroup (const char* nodeNameCorba,const char* groupNameCorba)  throw (Error);

  virtual bool applyConfiguration(const char* nodeNameCorba, const value_type* configuration)  throw (Error);

  virtual bool addLandmark(const char* nodeNameCorba, float size) throw (Error);
  virtual bool deleteLandmark(const char* nodeNameCorba) throw (Error);

  virtual bool setVisibility(const char* nodeNameCorba, const char* visibilityModeCorba)  throw (Error);
  virtual bool setWireFrameMode(const char* nodeNameCorba, const char* wireFrameModeCorba)  throw (Error);
  virtual bool setLightingMode(const char* nodeNameCorba, const char* lightingModeCorba)  throw (Error);

  virtual bool startCapture (const WindowID windowId, const char* filename,
      const char* extension) throw (Error);
  virtual bool stopCapture (const WindowID windowId) throw (Error);
  virtual bool writeNodeFile (const WindowID windowId, const char* filename) throw (Error);
}; // end of class

} /* namespace impl */
} /* namespace corbaServer */
} /* namespace graphics */

#endif /* SCENEVIEWER_CORBASERVER_GRAPHICALINTERFACE_HH */
