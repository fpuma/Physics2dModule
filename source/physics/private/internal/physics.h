#pragma once
#include <physics/iphysics.h>

#include <internal/simulation/world/world.h>
#include <internal/simulation/frameparts/framebody.h>
#include <internal/simulation/frameparts/frametrigger.h>

namespace puma::physics
{
    class Physics : public IPhysics, public NonCopyable
    {
    public:
                
        void update( float _deltaTime ) override;

        WorldID addWorld( Vec2 _gravity ) override;

        void setDefaultWorld( WorldID _worldId ) override { m_defaultWorldIndex = _worldId.value(); }
        World* getDefaultWorld() override{ return &m_worlds[m_defaultWorldIndex]; }
        const World* getDefaultWorld() const override { return &m_worlds[m_defaultWorldIndex]; }

        World* getWorld( WorldID _worldId ) override;
        const World* getWorld( WorldID _worldId ) const override;

        IFrame* getFrame( FrameID _frameId ) override;
        const IFrame* getFrame( FrameID _frameId ) const override;

        DynamicFrame* getDynamicFrame( FrameID _frameId ) override;
        const DynamicFrame* getDynamicFrame( FrameID _frameId ) const override;
        
        StaticFrame* getStaticFrame( FrameID _frameId ) override;
        const StaticFrame* getStaticFrame( FrameID _frameId ) const override;
        
        KinematicFrame* getKinematicFrame( FrameID _frameId ) override;
        const KinematicFrame* getKinematicFrame( FrameID _frameId ) const override;
        
        IFramePart* getFramePart( FramePartID _framePartId ) override;
        const IFramePart* getFramePart( FramePartID _framePartId ) const override;
        
        FrameBody* getFrameBody( FramePartID _framePartId ) override;
        const FrameBody* getFrameBody( FramePartID _framePartId ) const override;
                
        FrameTrigger* getFrameTrigger( FramePartID _framePartId ) override;
        const FrameTrigger* getFrameTrigger( FramePartID _framePartId ) const override;

        FrameType getFrameType( FrameID _frameId ) const override;
        FrameType getFrameType( FramePartID  _framePartId ) const override;
        FramePartType getFramePartType( FramePartID _framePartId ) const override;

    private:

        std::vector<World> m_worlds = {};

        u32 m_defaultWorldIndex = kMaxU32;
    };
}