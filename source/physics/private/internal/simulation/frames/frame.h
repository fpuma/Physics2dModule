#pragma once
#include <physics/geometry/vec2.h>
#include <physics/simulation/frames/iframe.h>

#include <internal/simulation/frameparts/framebody.h>
#include <internal/simulation/frameparts/frametrigger.h>

class b2Body;

namespace puma::physics
{
    class World;

    class Frame : public NonCopyable
    {
    public:
        Frame() = delete;
        Frame( b2Body* _body, const World* _worldPtr, FrameID _frameId );
        Frame( Frame&& _other ) noexcept;
        virtual ~Frame();

        FrameID getID() const { return m_frameId; }

        Vec2 getPosition() const;
        void setPosition( const Vec2& _position );

        float getAngle() const;
        void setAngle( float _angle );

        Vec2 getLinearVelocity() const;
        void setLinearVelocity( const Vec2& _linearVelocity );

        float getAngularVelocity() const;
        void setAngularVelocity( float _angularVelocity );

        void applyForce( const Vec2& _force, const Vec2& _worldPoint );
        void applyForceToCenter( const Vec2& _force );

        void applyTorque( float _torque );

        void applyLinearImpulse( const Vec2& _impulse, const Vec2& _worldPoint );
        void applyLinearImpulseToCenter( const Vec2& _impulse );

        void applyAngularImpulse( float _impulse );

        void setTransform( const Vec2& _position, float _angle );

        FramePartID addBody( const BodyInfo& _bodyInfo );
        FramePartID addTrigger( const TriggerInfo& _triggerInfo );

        bool isValid() const;

        FrameBody* getFrameBody( PhysicsID _index ) { assert( _index < m_frameBodies.size() ); return &m_frameBodies[_index]; }
        FrameTrigger* getFrameTrigger( PhysicsID _index ) { assert( _index < m_frameTriggers.size() ); return &m_frameTriggers[_index]; }

        const FrameBody* getFrameBody( PhysicsID _index ) const { assert( _index < m_frameBodies.size() ); return &m_frameBodies[_index]; }
        const FrameTrigger* getFrameTrigger( PhysicsID _index ) const { assert( _index < m_frameTriggers.size() ); return &m_frameTriggers[_index]; }

    private:
        b2Body* m_b2Body = nullptr;

        const World* m_world = nullptr;

        std::vector<FrameBody> m_frameBodies;
        std::vector<FrameTrigger> m_frameTriggers;

        FrameID m_frameId;
    };
}