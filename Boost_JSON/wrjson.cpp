#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>



using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

namespace pt = boost::property_tree;

pt::ptree root;

read_json("bdd.json",root);


 
 