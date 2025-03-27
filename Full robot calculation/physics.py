"""
Physics calculations for basketball trajectories.
"""
import numpy as np
import math

def calculate_height_at_target(v0, angle_degrees, h0_m, target_distance_m):
    """
    Calculate ball height at target position.
    
    Args:
        v0: Initial velocity in m/s
        angle_degrees: Launch angle in degrees
        h0_m: Initial height in meters
        target_distance_m: Horizontal distance to target in meters
        
    Returns:
        Height at target position in meters, or -1 if trajectory is invalid
    """
    # Physics constants
    g = 9.81  # Gravity acceleration in m/s²
    
    # Calculate trajectory parameters
    angle_rad = np.radians(angle_degrees)
    vx0 = v0 * np.cos(angle_rad)
    vy0 = v0 * np.sin(angle_rad)
    
    # Time to reach target
    if vx0 > 0:
        t_target = target_distance_m / vx0
        
        # Calculate ball height at target position
        ball_height = h0_m + vy0 * t_target - 0.5 * g * t_target**2
        return ball_height
    
    return -1  # Invalid trajectory

def calculate_max_height(v0, angle_degrees, h0_m):
    """
    Calculate maximum height of trajectory.
    
    Args:
        v0: Initial velocity in m/s
        angle_degrees: Launch angle in degrees
        h0_m: Initial height in meters
        
    Returns:
        Maximum height of trajectory in meters
    """
    g = 9.81  # Gravity acceleration in m/s²
    angle_rad = np.radians(angle_degrees)
    vy0 = v0 * np.sin(angle_rad)
    
    # Maximum height is reached when vertical velocity is zero
    if vy0 <= 0:  # If initial vertical velocity is negative or zero
        return h0_m
    
    # Maximum height
    h_max = h0_m + (vy0**2) / (2*g)
    return h_max

def is_basket(v0, angle_degrees, h0_m, target_distance_m, basket_height_m, basket_radius_m):
    """
    Check if shot is a basket.
    
    Args:
        v0: Initial velocity in m/s
        angle_degrees: Launch angle in degrees
        h0_m: Initial height in meters
        target_distance_m: Horizontal distance to target in meters
        basket_height_m: Basket height in meters
        basket_radius_m: Basket radius in meters
        
    Returns:
        True if shot is a basket, False otherwise
    """
    ball_height = calculate_height_at_target(v0, angle_degrees, h0_m, target_distance_m)
    if ball_height < 0:
        return False  # Invalid trajectory
    
    # Check if the ball goes through the basket
    return abs(ball_height - basket_height_m) < basket_radius_m

def is_valid_trajectory(v0, angle_degrees, h0_m, target_distance_m, basket_height_m, 
                        basket_radius_m, min_height_m, min_angle):
    """
    Check if a trajectory satisfies all requirements.
    
    Args:
        v0: Initial velocity in m/s
        angle_degrees: Launch angle in degrees
        h0_m: Initial height in meters
        target_distance_m: Horizontal distance to target in meters
        basket_height_m: Basket height in meters
        basket_radius_m: Basket radius in meters
        min_height_m: Minimum trajectory height in meters
        min_angle: Minimum launch angle in degrees
        
    Returns:
        True if trajectory is valid, False otherwise
    """
    # Check if angle is at least the minimum
    if angle_degrees < min_angle:
        return False
    
    # Check if max height is at least the minimum required
    max_height = calculate_max_height(v0, angle_degrees, h0_m)
    if max_height < min_height_m:
        return False
    
    # Check if it's a basket
    return is_basket(v0, angle_degrees, h0_m, target_distance_m, basket_height_m, basket_radius_m)

def generate_trajectory_data(v0, angle_degrees, h0_m, target_distance_m):
    """
    Generate trajectory data points.
    
    Args:
        v0: Initial velocity in m/s
        angle_degrees: Launch angle in degrees
        h0_m: Initial height in meters
        target_distance_m: Horizontal distance to target in meters
        
    Returns:
        Tuple containing (x_points, y_points, ball_height_at_target, max_height, time_to_target)
        or (None, None, 0, 0, 0) if trajectory is invalid
    """
    g = 9.81  # Gravity acceleration in m/s²
    
    # Calculate trajectory
    angle_rad = np.radians(angle_degrees)
    vx0 = v0 * np.cos(angle_rad)
    vy0 = v0 * np.sin(angle_rad)
    
    # Time to reach basket horizontally
    if vx0 > 0:
        t_target = target_distance_m / vx0
        
        # Calculate points along trajectory
        t = np.linspace(0, t_target * 1.2, num=100)  # Extra time to show full arc
        x = vx0 * t
        y = h0_m + vy0 * t - 0.5 * g * t**2
        
        # Calculate ball height at target
        ball_height_at_target = h0_m + vy0 * t_target - 0.5 * g * t_target**2
        
        # Calculate maximum height
        max_height = calculate_max_height(v0, angle_degrees, h0_m)
        
        return x, y, ball_height_at_target, max_height, t_target
    
    return None, None, 0, 0, 0
