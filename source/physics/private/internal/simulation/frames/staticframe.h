#pragma once
#include <physics/simulation/frames/istaticframe.h>

#include <internal/simulation/frames/frame.h>

class b2Body;

namespace puma::physics
{
    class World;

    class StaticFrame : public IStaticFrame, public NonCopyable
    {
    public:
        StaticFrame() = delete;
        StaticFrame( b2Body* _body, const World* _world, FrameID _id );
        StaticFrame( StaticFrame&& _other ) noexcept : m_frame( std::move( _other.m_frame ) ) {}

        FrameID getID() const override { return m_frame.getID(); }

        Vec2 getPosition() const override;
        void setPosition( const Vec2& _position ) override;

        float getAngle() const override;
        void setAngle( float _angle ) override;

        void setTransform( const Vec2& _position, float _angle ) override;

        FramePartID addBody( const BodyInfo& _bodyInfo ) override;
        FramePartID addTrigger( const TriggerInfo& _triggerInfo ) override;

        bool isValid() const override;

        //Internal

        FrameBody* getFrameBody( PhysicsID _index ) { return m_frame.getFrameBody( _index ); }
        FrameTrigger* getFrameTrigger( PhysicsID _index ) { return m_frame.getFrameTrigger( _index ); }

        const FrameBody* getFrameBody( PhysicsID _index ) const { return m_frame.getFrameBody( _index ); }
        const FrameTrigger* getFrameTrigger( PhysicsID _index ) const { return m_frame.getFrameTrigger( _index ); }

    private:

        Frame m_frame;
    };    
}