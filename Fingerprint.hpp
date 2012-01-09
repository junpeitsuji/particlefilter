#pragma once

#include <stdlib.h>  // getenv()利用のため
#include <string>    // std::stringクラス
#include <map>       // std::mapクラス
#include <list>      // std::listクラス
#include <fstream>   // 

// Boost 1.46のライブラリ利用のためのヘッダファイル読み込み
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/string.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/list.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

namespace OpenLab {

	namespace io {

		namespace fp {
			// データクラス
			class Location;
			class Fingerprint;

			// フィンガープリントの位置情報を表すクラス
			class Location {
			public:
				Location(){}
				~Location(){}
				std::string name; // 
				double x, y, z;

			private:
				friend class boost::serialization::access;
				template <class Archive>
				void serialize(Archive& archive, unsigned int version)
				{
					static_cast<void>(version); // No use
					archive & boost::serialization::make_nvp("Name", name);
					archive & boost::serialization::make_nvp("X", x);
					archive & boost::serialization::make_nvp("Y", y);
					archive & boost::serialization::make_nvp("Z", z);
				}
			};

			// フィンガープリントの情報を保持するクラス
			class Fingerprint {
			public:
				Fingerprint(){}
				~Fingerprint(){}

				int                   id;          // ID
				Location              location;    // location of Fingerprint
				std::map<int, double> values;      // map of value in Fingerprint 
				std::map<int, double> deviations;  // 
				std::map<int, int>    nums;        //

			private:
				friend class boost::serialization::access;
				template <class Archive>
				void serialize(Archive& archive, unsigned int version)
				{
					static_cast<void>(version); // No use
					archive & boost::serialization::make_nvp("Id", id);
					archive & boost::serialization::make_nvp("Location", location);
					archive & boost::serialization::make_nvp("Values", values);
					archive & boost::serialization::make_nvp("Deviations", deviations);
					archive & boost::serialization::make_nvp("Nums", nums);
				}
			};


			// リーダーファクトリークラス
			class FingerprintIOFactory;

			// リーダークラスインタフェース
			class AbstractFingerprintIO;
			// 実装リーダークラス
			class RawfileFingerprintIO;
			class XmlFingerprintIO;
		};

	};

};

// 自作ヘッダファイル読み込み
#include "OpenLab/io/fp/AbstractFingerprintIO.h"
#include "OpenLab/io/fp/RawfileFingerprintIO.h"
#include "OpenLab/io/fp/XmlFingerprintIO.h"
#include "OpenLab/io/fp/FingerpintIOFactory.h"

