/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

/**************************************************************************
** ODD: OpenDRIVE Designer
**   Frank Naegele (c) 2010
**   <mail@f-naegele.de>
**   21.05.2010
**
**************************************************************************/

#ifndef OSCOBJECTCOMMANDS_HPP
#define OSCOBJECTCOMMANDS_HPP


#include "datacommand.hpp"

// Data //
//
#include "src/data/oscsystem/oscelement.hpp"

#include <QMap>

namespace OpenScenario
{
class oscObjectBase;
class OpenScenarioBase;
class oscMember;
template<typename T>
class oscValue;
}

class OSCBase;


//#########################//
// AddOSCObjectCommand //
//#########################//

class AddOSCObjectCommand : public DataCommand
{
public:
	explicit AddOSCObjectCommand(const OpenScenario::oscObjectBase *parentObject, OSCBase *oscBase, const std::string &name, OSCElement *element, DataCommand *parent = NULL);
    virtual ~AddOSCObjectCommand();

    virtual int id() const
    {
        return 0x1011;
    }

    virtual void undo();
    virtual void redo();

private:
    AddOSCObjectCommand(); /* not allowed */
    AddOSCObjectCommand(const AddOSCObjectCommand &); /* not allowed */
    AddOSCObjectCommand &operator=(const AddOSCObjectCommand &); /* not allowed */

private:
	OpenScenario::OpenScenarioBase * openScenarioBase_;
    std::string typeName_;
	const OpenScenario::oscObjectBase * parentObject_;

	OSCElement *element_;
	OSCBase *oscBase_;
	OpenScenario::oscMember *member_;
};

//#########################//
// RemoveOSCObjectCommand //
//#########################//

class RemoveOSCObjectCommand : public DataCommand
{
public:
    explicit RemoveOSCObjectCommand(OSCElement *element,DataCommand *parent = NULL);
    virtual ~RemoveOSCObjectCommand();

    virtual int id() const
    {
        return 0x1011;
    }

    virtual void undo();
    virtual void redo();

private:
    RemoveOSCObjectCommand(); /* not allowed */
    RemoveOSCObjectCommand(const RemoveOSCObjectCommand &); /* not allowed */
    RemoveOSCObjectCommand &operator=(const RemoveOSCObjectCommand &); /* not allowed */

private:
	const OpenScenario::OpenScenarioBase * openScenarioBase_;
    const OpenScenario::oscObjectBase *object_;

	OSCBase *oscBase_;
	OSCElement *element_;
};

//#########################//
// SetOSCObjectPropertiesCommand //
//#########################//
template<typename T>
class SetOSCObjectPropertiesCommand : public DataCommand
{
public:
    explicit SetOSCObjectPropertiesCommand(OSCElement *element, std::string &memberName, OpenScenario::oscValue<T> value, DataCommand *parent = NULL)
	{
	// Check for validity //
    //
    if (!element)
    {
        setInvalid(); // Invalid
        setText(QObject::tr("SetOSCObjectPropertiesCommand: Internal error! No OSCElement specified."));
        return;
    }
    else
    {
        setValid();
        setText(QObject::tr("SetProperties"));
    }

	element_ = element;
	object_ = element_->getObject();
	newOSCValue_ = value;
	member_ = object_->getMembers().at(memberName);
//	oldOSCValue_ = member_->getValue();
	}
    virtual ~SetOSCObjectPropertiesCommand()
	{
		// Clean up //
    //
    if (isUndone())
    {
    }
    else
    {
    }
	}


    virtual int id() const
    {
        return 0x1011;
    }

    virtual void undo()
	{

//	member_->setValue(oldOSCValue_);
	element_->addOSCElementChanges(DataElement::CDE_ChildChange);

    setUndone();
	}

    virtual void redo()
	{
		//	member_->setValue(newOSCValue_);
	element_->addOSCElementChanges(DataElement::CDE_ChildChange);

    setRedone();
	}

private:
    SetOSCObjectPropertiesCommand(); /* not allowed */
    SetOSCObjectPropertiesCommand(const SetOSCObjectPropertiesCommand &); /* not allowed */
    SetOSCObjectPropertiesCommand &operator=(const SetOSCObjectPropertiesCommand &); /* not allowed */

private:
	OSCElement *element_;
    const OpenScenario::oscObjectBase *object_;
	OpenScenario::oscMember *member_;
	OpenScenario::oscValue<T> newOSCValue_;
	OpenScenario::oscValue<T> oldOSCValue_;
};

#endif // OSCOBJECTCOMMANDS_HPP