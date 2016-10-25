/*
  Copyright (C) 2007 Rory Walsh

  Cabbage is free software; you can redistribute it
  and/or modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  Cabbage is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

//   You should have received a copy of the GNU Lesser General Public
  License along with Csound; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
  02111-1307 USA

*/
#ifndef CABBPARSE_H
#define CABBPARSE_H


#include "../Utilities/CabbageUtilities.h"
#include "../CabbageIds.h"

class CabbageWidget : public CabbageUtilities
{
//    Array<int> tableNumbers;
//    Array<float> tableChannelValues;
    String warningMessages;
    bool refreshFromDisk;

public:
    CabbageWidget(String compStr, int ID);
    ~CabbageWidget(){};
	static void setWidgetState(ValueTree widgetData, String lineFromCsd, int ID);
	static void setCustomWidgetState(ValueTree widgetData, String lineFromCsd, String identifier=String::empty);
	
	
	
	
    void parse(String str, String identifier){};
    static float getNumProp(ValueTree widgetData, Identifier prop);
    static void setNumProp(ValueTree widgetData, Identifier prop, float val);
    void setTableChannelValues(int index, float val);
    float getTableChannelValues(int index);
    void addTableChannelValues();
    static void setStringProp(ValueTree widgetData, Identifier prop, String val);
    static void setStringProp(ValueTree widgetData, Identifier prop, int index, String value);
    static String getStringProp(ValueTree widgetData, Identifier prop);

    static String getPropsString();
    static String getColourProp(ValueTree widgetData, Identifier prop);
    static float getNumPropVal(ValueTree widgetData, Identifier prop);
    void scaleWidget(Point<float> scale);
    void setNumPropVal(Identifier prop, float val);
    static String getCabbageCodeFromIdentifiers(NamedValueSet props);
    static String getStringForIdentifier(var props, String identifier, String type);

	static void setProperty(ValueTree widgetData, Identifier name, const var &value)
	{
		const Array<var>* array = value.getArray();
		const ReferenceCountedObject* valueObject = value.getObject();

		if(array || valueObject)
		{
			widgetData.addChild(ValueTree(name.toString()), -1, 0);
			for( int i = 0; i < array->size() ; i++)
				widgetData.getChildWithName(name.toString()).setProperty(name.toString()+"_"+String(i), array->getReference(i).toString(), 0);		
		}
		else		
			widgetData.setProperty(name, value, 0);		
	}
	
	//ValueTree getValueTree()	{	return widgetData;	}
	
	static var getWidgetPropertyWithDefault(ValueTree widgetData, Identifier name, const var &value)
	{
		return widgetData.getProperty(name, value);
	}	

	static var getProperty(ValueTree widgetData, Identifier name)
	{
		return widgetData.getProperty(name);
	}		

//	for(int i=0;i<cabbageWidgets.getNumChildren();i++)
//	{
//		const ValueTree valueTree = cabbageWidgets.getChild(i);
//		CabbageUtilities::debug(valueTree.getProperty(CabbageIdentifierIds::name).toString());
//		for( int y=0;y< valueTree.getChildWithName("channel").getNumProperties();y++)
//		{
//			const String name = valueTree.getChildWithName("channel").getPropertyName(y).toString();
//			CabbageUtilities::debug(valueTree.getChildWithName("channel").getProperty(name).toString());
//		}		
//	}
//	
    //static methods used for updating look and pos of GUI controls
    static Rectangle<int> getBoundsFromText(String text);
    static Colour getColourFromText(String text);
    static String getTextFromText(String text);
    static Point<int> getSizeFromText(String text);
    static Point<int> getPosFromText(String text);
    static float getSkewFromText(String text);
    static var getVarArrayFromText(String text);

    static StringArray getIdentifiers()
    {
        StringArray test;
        return test;
    }


    StringArray getStringArrayProp(Identifier prop);
    String getStringArrayPropValue(Identifier prop, int index);
    int getIntArrayPropValue(Identifier prop, int index);
    Array<int> getIntArrayProp(Identifier prop);
    var getVarArrayProp(Identifier prop);
    float getFloatArrayPropValue(Identifier prop, int index);
    Array<float> getFloatArrayProp(Identifier prop);
    void setStringArrayPropValue(Identifier prop, int index, String value);
    void setStringArrayProp(Identifier prop, var value);

};

#endif
