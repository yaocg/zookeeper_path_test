#include <iostream>
#include "Zookeeper.h"

using namespace std;

int main(void) {

  string path = "";
  string zkBrokers = "";

  vector<Zookeeper*>  zk;
  try {

    for (int i = 0; i < 5; i++ ){
      Zookeeper* t = new Zookeeper(zkBrokers);
      zk.push_back(t);
    }

  } catch (const ZookeeperException &zooex) {
    cout << "zookeeper exception:" << zooex.what() << endl;
    return -1;
  }

  for( int i = 0; i < zk.size(); i++ ) {
    vector<string> aaa = zk[i]->getChildren(path);
    cout << "have id:";
    for( int j = 0; j < aaa.size(); j++ )
    {
      cout << aaa[j] << ",";
    }

    cout << endl;
    cout << "-----id:" << (uint32_t)zk[i]->getUniqIdUint8(path) << endl;
  }

  for( int i = 0; i < zk.size(); i++ ) {
    delete zk[i];
  }

  return 0;
}
