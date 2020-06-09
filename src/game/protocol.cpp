#if 0

#include "ArduinoJson.hpp"

using namespace ArduinoJson;

extern "C" {
#include <stdio.h>
#include <stdlib.h>

#include "esp_err.h"
#include "esp_log.h"

#include "object.h"
#include "protocol.h"

    static const char* TAG = "protocol";
};

//{---------------------------------------------------------------------------------------------------------------------------------
static void protocol_spaceships_from_server( ArduinoJson::JsonDocument& game_json, game_state_t* game_state )
{
    auto spaceships_json = game_json[ "spaceships" ].as<ArduinoJson::JsonArray>();

    size_t index = 0;
    for( auto spaceship_n_json : spaceships_json )
    {
        if( index >= sizeof( game_state->spaceships ) / sizeof( *game_state->spaceships ) )
        {
            break;
        }
        game_state->spaceships[ index ].active = spaceship_n_json[ "active" ];
        if( game_state->spaceships[ index ].active )
        {
            if( index != game_state->current_player )
            {
                game_state->spaceships[ index ].px                      = spaceship_n_json[ "px" ];
                game_state->spaceships[ index ].py                      = spaceship_n_json[ "py" ];
                game_state->spaceships[ index ].vi                      = spaceship_n_json[ "vi" ];
                game_state->spaceships[ index ].vj                      = spaceship_n_json[ "vj" ];
            }
            game_state->spaceships[ index ].mode                    = spaceship_n_json[ "mode" ];
            game_state->spaceships[ index ].life                    = spaceship_n_json[ "life" ];
            game_state->spaceships[ index ].collision_countdown     = spaceship_n_json[ "collision_countdown" ];
            game_state->spaceships[ index ].collision_active        = spaceship_n_json[ "collision_active" ];
            game_state->spaceships[ index ].shield_active           = spaceship_n_json[ "shield_active" ];
            game_state->spaceships[ index ].shield_animation_number = spaceship_n_json[ "shield_animation_number" ];
            game_state->spaceships[ index ].alive_timer             = spaceship_n_json[ "alive_timer" ];
            game_state->spaceships[ index ].asteroids_counter       = spaceship_n_json[ "asteroids_counter" ];
        }
        index++;
    }
}

static void protocol_asteroids_from_server( ArduinoJson::JsonDocument& game_json, game_state_t* game_state )
{
    auto asteroids_json = game_json[ "asteroids" ].as<ArduinoJson::JsonArray>();

    size_t index = 0;
    for( auto asteroid_n_json : asteroids_json )
    {
        if( index >= sizeof( game_state->asteroids ) / sizeof( *game_state->asteroids ) )
        {
            break;
        }
        game_state->asteroids[ index ].active = asteroid_n_json[ "active" ];
        if( game_state->asteroids[ index ].active )
        {
            game_state->asteroids[ index ].px               = asteroid_n_json[ "px" ];
            game_state->asteroids[ index ].py               = asteroid_n_json[ "py" ];
            game_state->asteroids[ index ].vi               = asteroid_n_json[ "vi" ];
            game_state->asteroids[ index ].vj               = asteroid_n_json[ "vj" ];
            game_state->asteroids[ index ].number           = asteroid_n_json[ "number" ];
            game_state->asteroids[ index ].orientation      = asteroid_n_json[ "orientation" ];
            game_state->asteroids[ index ].life             = asteroid_n_json[ "life" ];
            game_state->asteroids[ index ].damage_countdown = asteroid_n_json[ "damage_countdown" ];
            game_state->asteroids[ index ].damage_active    = asteroid_n_json[ "damage_active" ];
        }
        index++;
    }
}

static void protocol_impacts_from_server( ArduinoJson::JsonDocument& game_json, game_state_t* game_state )
{
    auto impacts_json = game_json[ "impacts" ].as<ArduinoJson::JsonArray>();

    size_t index = 0;
    for( auto impact_n_json : impacts_json )
    {
        if( index >= sizeof( game_state->impacts ) / sizeof( *game_state->impacts ) )
        {
            break;
        }
        game_state->impacts[ index ].active = impact_n_json[ "active" ];
        if( game_state->impacts[ index ].active )
        {
            game_state->impacts[ index ].px                  = impact_n_json[ "px" ];
            game_state->impacts[ index ].py                  = impact_n_json[ "py" ];
            game_state->impacts[ index ].type                = impact_n_json[ "type" ];
            game_state->impacts[ index ].size                = impact_n_json[ "size" ];
            game_state->impacts[ index ].animation_number    = impact_n_json[ "animation_number" ];
            game_state->impacts[ index ].animation_countdown = impact_n_json[ "animation_countdown" ];
        }
        index++;
    }
}

static void protocol_projectiles_from_server( ArduinoJson::JsonDocument& game_json, game_state_t* game_state )
{
    auto projectiles_json = game_json[ "projectiles" ].as<ArduinoJson::JsonArray>();

    size_t index = 0;
    for( auto projectile_n_json : projectiles_json )
    {
        if( index >= sizeof( game_state->projectiles ) / sizeof( *game_state->projectiles ) )
        {
            break;
        }
        game_state->projectiles[ index ].active = projectile_n_json[ "active" ];
        if( game_state->projectiles[ index ].active )
        {
            game_state->projectiles[ index ].px                  = projectile_n_json[ "px" ];
            game_state->projectiles[ index ].py                  = projectile_n_json[ "py" ];
            game_state->projectiles[ index ].vi                  = projectile_n_json[ "vi" ];
            game_state->projectiles[ index ].vj                  = projectile_n_json[ "vj" ];
            game_state->projectiles[ index ].owner               = projectile_n_json[ "owner" ];
            game_state->projectiles[ index ].type                = projectile_n_json[ "type" ];
            game_state->projectiles[ index ].animation_number    = projectile_n_json[ "animation_number" ];
            game_state->projectiles[ index ].animation_countdown = projectile_n_json[ "animation_countdown" ];
        }
        index++;
    }
}

static void protocol_pickups_from_server( ArduinoJson::JsonDocument& game_json, game_state_t* game_state )
{
    auto pickups_json = game_json[ "pickups" ].as<ArduinoJson::JsonArray>();

    size_t index = 0;
    for( auto pickup_n_json : pickups_json )
    {
        if( index >= sizeof( game_state->pickups ) / sizeof( *game_state->pickups ) )
        {
            break;
        }
        game_state->pickups[ index ].active = pickup_n_json[ "active" ];
        if( game_state->pickups[ index ].active )
        {
            game_state->pickups[ index ].px                  = pickup_n_json[ "px" ];
            game_state->pickups[ index ].py                  = pickup_n_json[ "py" ];
            game_state->pickups[ index ].vi                  = pickup_n_json[ "vi" ];
            game_state->pickups[ index ].vj                  = pickup_n_json[ "vj" ];
            game_state->pickups[ index ].type                = pickup_n_json[ "type" ];
            game_state->pickups[ index ].trajectory_progress = pickup_n_json[ "trajectory_progress" ];
        }
        index++;
    }
}

static void protocol_meteors_from_server( ArduinoJson::JsonDocument& game_json, game_state_t* game_state )
{
    auto meteors_json = game_json[ "meteors" ].as<ArduinoJson::JsonArray>();

    size_t index = 0;
    for( auto meteor_n_json : meteors_json )
    {
        if( index >= sizeof( game_state->meteors ) / sizeof( *game_state->meteors ) )
        {
            break;
        }
        game_state->meteors[ index ].active = meteor_n_json[ "active" ];
        if( game_state->meteors[ index ].active )
        {
            game_state->meteors[ index ].px                  = meteor_n_json[ "px" ];
            game_state->meteors[ index ].py                  = meteor_n_json[ "py" ];
            game_state->meteors[ index ].vi                  = meteor_n_json[ "vi" ];
            game_state->meteors[ index ].vj                  = meteor_n_json[ "vj" ];
            game_state->meteors[ index ].direction           = meteor_n_json[ "direction" ];
            game_state->meteors[ index ].animation_number    = meteor_n_json[ "animation_number" ];
            game_state->meteors[ index ].animation_countdown = meteor_n_json[ "animation_countdown" ];
            game_state->meteors[ index ].arrow_active        = meteor_n_json[ "arrow_active" ];
            game_state->meteors[ index ].arrow_countdown     = meteor_n_json[ "arrow_countdown" ];
            game_state->meteors[ index ].arrow_progress      = meteor_n_json[ "arrow_progress" ];
        }
        index++;
    }
}
//}---------------------------------------------------------------------------------------------------------------------------------
//{---------------------------------------------------------------------------------------------------------------------------------
static void protocol_spaceships_to_client( ArduinoJson::JsonDocument& game_json, const game_state_t* game_state )
{
    auto spaceships_json = game_json.createNestedArray( "spaceships" );

    for( size_t index = 0; index < sizeof( game_state->spaceships ) / sizeof( *game_state->spaceships ); index++ )
    {
        auto spaceship_n_json = spaceships_json.createNestedObject();

        spaceship_n_json[ "active" ] = game_state->spaceships[ index ].active;
        if( not game_state->spaceships[ index ].active )
        {
            continue;
        }
        spaceship_n_json[ "px" ]                      = game_state->spaceships[ index ].px;
        spaceship_n_json[ "py" ]                      = game_state->spaceships[ index ].py;
        spaceship_n_json[ "vi" ]                      = game_state->spaceships[ index ].vi;
        spaceship_n_json[ "vj" ]                      = game_state->spaceships[ index ].vj;
        spaceship_n_json[ "mode" ]                    = game_state->spaceships[ index ].mode;
        spaceship_n_json[ "life" ]                    = game_state->spaceships[ index ].life;
        spaceship_n_json[ "collision_countdown" ]     = game_state->spaceships[ index ].collision_countdown;
        spaceship_n_json[ "collision_active" ]        = game_state->spaceships[ index ].collision_active;
        spaceship_n_json[ "shield_active" ]           = game_state->spaceships[ index ].shield_active;
        spaceship_n_json[ "shield_animation_number" ] = game_state->spaceships[ index ].shield_animation_number;
        spaceship_n_json[ "alive_timer" ]             = game_state->spaceships[ index ].alive_timer;
        spaceship_n_json[ "asteroids_counter" ]       = game_state->spaceships[ index ].asteroids_counter;
    }
}

static void protocol_asteroids_to_client( ArduinoJson::JsonDocument& game_json, const game_state_t* game_state )
{
    auto asteroids_json = game_json.createNestedArray( "asteroids" );

    for( size_t index = 0; index < sizeof( game_state->asteroids ) / sizeof( *game_state->asteroids ); index++ )
    {
        auto asteroid_n_json = asteroids_json.createNestedObject();

        asteroid_n_json[ "active" ] = game_state->asteroids[ index ].active;
        if( not game_state->asteroids[ index ].active )
        {
            continue;
        }
        asteroid_n_json[ "px" ]               = game_state->asteroids[ index ].px;
        asteroid_n_json[ "py" ]               = game_state->asteroids[ index ].py;
        asteroid_n_json[ "vi" ]               = game_state->asteroids[ index ].vi;
        asteroid_n_json[ "vj" ]               = game_state->asteroids[ index ].vj;
        asteroid_n_json[ "number" ]           = game_state->asteroids[ index ].number;
        asteroid_n_json[ "orientation" ]      = game_state->asteroids[ index ].orientation;
        asteroid_n_json[ "life" ]             = game_state->asteroids[ index ].life;
        asteroid_n_json[ "damage_countdown" ] = game_state->asteroids[ index ].damage_countdown;
        asteroid_n_json[ "damage_active" ]    = game_state->asteroids[ index ].damage_active;
    }
}

static void protocol_impacts_to_client( ArduinoJson::JsonDocument& game_json, const game_state_t* game_state )
{
    auto impacts_json = game_json.createNestedArray( "impacts" );

    for( size_t index = 0; index < sizeof( game_state->impacts ) / sizeof( *game_state->impacts ); index++ )
    {
        auto impact_n_json = impacts_json.createNestedObject();

        impact_n_json[ "active" ] = game_state->impacts[ index ].active;
        if( not game_state->impacts[ index ].active )
        {
            continue;
        }
        impact_n_json[ "px" ]                  = game_state->impacts[ index ].px;
        impact_n_json[ "py" ]                  = game_state->impacts[ index ].py;
        impact_n_json[ "type" ]                = game_state->impacts[ index ].type;
        impact_n_json[ "size" ]                = game_state->impacts[ index ].size;
        impact_n_json[ "animation_number" ]    = game_state->impacts[ index ].animation_number;
        impact_n_json[ "animation_countdown" ] = game_state->impacts[ index ].animation_countdown;
    }
}

static void protocol_projectiles_to_client( ArduinoJson::JsonDocument& game_json, const game_state_t* game_state )
{
    auto projectiles_json = game_json.createNestedArray( "projectiles" );

    for( size_t index = 0; index < sizeof( game_state->projectiles ) / sizeof( *game_state->projectiles ); index++ )
    {
        auto projectile_n_json = projectiles_json.createNestedObject();

        projectile_n_json[ "active" ] = game_state->projectiles[ index ].active;
        if( not game_state->projectiles[ index ].active )
        {
            continue;
        }
        projectile_n_json[ "px" ]                  = game_state->projectiles[ index ].px;
        projectile_n_json[ "py" ]                  = game_state->projectiles[ index ].py;
        projectile_n_json[ "vi" ]                  = game_state->projectiles[ index ].vi;
        projectile_n_json[ "vj" ]                  = game_state->projectiles[ index ].vj;
        projectile_n_json[ "owner" ]               = game_state->projectiles[ index ].owner;
        projectile_n_json[ "type" ]                = game_state->projectiles[ index ].type;
        projectile_n_json[ "animation_number" ]    = game_state->projectiles[ index ].animation_number;
        projectile_n_json[ "animation_countdown" ] = game_state->projectiles[ index ].animation_countdown;
    }
}

static void protocol_pickups_to_client( ArduinoJson::JsonDocument& game_json, const game_state_t* game_state )
{
    auto pickups_json = game_json.createNestedArray( "pickups" );

    for( size_t index = 0; index < sizeof( game_state->pickups ) / sizeof( *game_state->pickups ); index++ )
    {
        auto pickup_n_json = pickups_json.createNestedObject();

        pickup_n_json[ "active" ] = game_state->pickups[ index ].active;
        if( not game_state->pickups[ index ].active )
        {
            continue;
        }
        pickup_n_json[ "px" ]                  = game_state->pickups[ index ].px;
        pickup_n_json[ "py" ]                  = game_state->pickups[ index ].py;
        pickup_n_json[ "vi" ]                  = game_state->pickups[ index ].vi;
        pickup_n_json[ "vj" ]                  = game_state->pickups[ index ].vj;
        pickup_n_json[ "type" ]                = game_state->pickups[ index ].type;
        pickup_n_json[ "trajectory_progress" ] = game_state->pickups[ index ].trajectory_progress;
    }
}

static void protocol_meteors_to_client( ArduinoJson::JsonDocument& game_json, const game_state_t* game_state )
{
    auto meteors_json = game_json.createNestedArray( "meteors" );

    for( size_t index = 0; index < sizeof( game_state->meteors ) / sizeof( *game_state->meteors ); index++ )
    {
        auto meteor_n_json = meteors_json.createNestedObject();

        meteor_n_json[ "active" ] = game_state->meteors[ index ].active;
        if( not game_state->meteors[ index ].active )
        {
            continue;
        }
        meteor_n_json[ "px" ]                  = game_state->meteors[ index ].px;
        meteor_n_json[ "py" ]                  = game_state->meteors[ index ].py;
        meteor_n_json[ "vi" ]                  = game_state->meteors[ index ].vi;
        meteor_n_json[ "vj" ]                  = game_state->meteors[ index ].vj;
        meteor_n_json[ "direction" ]           = game_state->meteors[ index ].direction;
        meteor_n_json[ "animation_number" ]    = game_state->meteors[ index ].animation_number;
        meteor_n_json[ "animation_countdown" ] = game_state->meteors[ index ].animation_countdown;
        meteor_n_json[ "arrow_active" ]        = game_state->meteors[ index ].arrow_active;
        meteor_n_json[ "arrow_countdown" ]     = game_state->meteors[ index ].arrow_countdown;
        meteor_n_json[ "arrow_progress" ]      = game_state->meteors[ index ].arrow_progress;
    }
}
//}---------------------------------------------------------------------------------------------------------------------------------
//{---------------------------------------------------------------------------------------------------------------------------------
static void protocol_spaceships_to_server( ArduinoJson::JsonDocument& game_json, const game_state_t* game_state )
{
    auto spaceships_json = game_json.createNestedArray( "spaceships" );

    const auto index = game_state->current_player;

    auto spaceship_n_json = spaceships_json.createNestedObject();

    spaceship_n_json[ "active" ] = game_state->spaceships[ index ].active;
    if( game_state->spaceships[ index ].active )
    {
        spaceship_n_json[ "px" ]                      = game_state->spaceships[ index ].px;
        spaceship_n_json[ "py" ]                      = game_state->spaceships[ index ].py;
        spaceship_n_json[ "vi" ]                      = game_state->spaceships[ index ].vi;
        spaceship_n_json[ "vj" ]                      = game_state->spaceships[ index ].vj;
        spaceship_n_json[ "mode" ]                    = game_state->spaceships[ index ].mode;
        spaceship_n_json[ "life" ]                    = game_state->spaceships[ index ].life;
        spaceship_n_json[ "collision_countdown" ]     = game_state->spaceships[ index ].collision_countdown;
        spaceship_n_json[ "collision_active" ]        = game_state->spaceships[ index ].collision_active;
        spaceship_n_json[ "shield_active" ]           = game_state->spaceships[ index ].shield_active;
        spaceship_n_json[ "shield_animation_number" ] = game_state->spaceships[ index ].shield_animation_number;
        spaceship_n_json[ "alive_timer" ]             = game_state->spaceships[ index ].alive_timer;
        spaceship_n_json[ "asteroids_counter" ]       = game_state->spaceships[ index ].asteroids_counter;
    }
}
//}---------------------------------------------------------------------------------------------------------------------------------
//{---------------------------------------------------------------------------------------------------------------------------------
static void protocol_spaceships_from_client( ArduinoJson::JsonDocument& game_json, game_state_t* game_state, uint8_t client_player )
{
    auto spaceships_json = game_json[ "spaceships" ].as<ArduinoJson::JsonArray>();

    if( client_player >= sizeof( game_state->spaceships ) / sizeof( *game_state->spaceships ) || client_player == game_state->current_player )
    {
        return;
    }

    auto spaceship_n_json = spaceships_json[ 0 ];

    game_state->spaceships[ client_player ].active = spaceship_n_json[ "active" ];
    if( game_state->spaceships[ client_player ].active )
    {
        game_state->spaceships[ client_player ].px                      = spaceship_n_json[ "px" ];
        game_state->spaceships[ client_player ].py                      = spaceship_n_json[ "py" ];
        game_state->spaceships[ client_player ].vi                      = spaceship_n_json[ "vi" ];
        game_state->spaceships[ client_player ].vj                      = spaceship_n_json[ "vj" ];
        game_state->spaceships[ client_player ].mode                    = spaceship_n_json[ "mode" ];
        game_state->spaceships[ client_player ].life                    = spaceship_n_json[ "life" ];
        game_state->spaceships[ client_player ].collision_countdown     = spaceship_n_json[ "collision_countdown" ];
        game_state->spaceships[ client_player ].collision_active        = spaceship_n_json[ "collision_active" ];
        game_state->spaceships[ client_player ].shield_active           = spaceship_n_json[ "shield_active" ];
        game_state->spaceships[ client_player ].shield_animation_number = spaceship_n_json[ "shield_animation_number" ];
        game_state->spaceships[ client_player ].alive_timer             = spaceship_n_json[ "alive_timer" ];
        game_state->spaceships[ client_player ].asteroids_counter       = spaceship_n_json[ "asteroids_counter" ];
    }
}
//}---------------------------------------------------------------------------------------------------------------------------------
//{---------------------------------------------------------------------------------------------------------------------------------
static ArduinoJson::StaticJsonDocument<20000> game_json{ };

void protocol_game_from_server( game_state_t* game_state, const char* buffer, size_t length )
{
    game_json.clear();

    //ArduinoJson::deserializeMsgPack( game_json, buffer, length );
    ArduinoJson::deserializeJson( game_json, buffer, length );

    protocol_spaceships_from_server ( game_json, game_state );
    protocol_asteroids_from_server  ( game_json, game_state );
    protocol_impacts_from_server    ( game_json, game_state );
    protocol_projectiles_from_server( game_json, game_state );
    protocol_pickups_from_server    ( game_json, game_state );
    protocol_meteors_from_server    ( game_json, game_state );
}


// JSON        -> buffer(char) = 16517 / buffer(json) = 24543 / t = 9736
// MessagePack -> buffer(char) = 10161 / buffer(json) = 11633 / t = 3915

size_t protocol_game_to_client( const game_state_t* game_state, char* buffer, size_t length )
{
    game_json.clear();

    protocol_spaceships_to_client ( game_json, game_state );
    protocol_asteroids_to_client  ( game_json, game_state );
    protocol_impacts_to_client    ( game_json, game_state );
    protocol_projectiles_to_client( game_json, game_state );
    protocol_pickups_to_client    ( game_json, game_state );
    protocol_meteors_to_client    ( game_json, game_state );

    //return ArduinoJson::serializeMsgPack( game_json, buffer, length );
    return ArduinoJson::serializeJson( game_json, buffer, length );
}

void protocol_game_from_client( game_state_t* game_state, const char* buffer, size_t length  )
{
    game_json.clear();

    //ArduinoJson::deserializeMsgPack( game_json, buffer, length );
    ArduinoJson::deserializeJson( game_json, buffer, length );

    const uint8_t client_player = game_json[ "player" ];
    protocol_spaceships_from_client ( game_json, game_state, client_player );
}

size_t protocol_game_to_server( const game_state_t* game_state, char* buffer, size_t length )
{
    game_json.clear();

    game_json[ "player" ] = game_state->current_player;
    protocol_spaceships_to_server( game_json, game_state );

    //return ArduinoJson::serializeMsgPack( game_json, buffer, length );
    return ArduinoJson::serializeJson( game_json, buffer, length );
}
//}---------------------------------------------------------------------------------------------------------------------------------

#endif