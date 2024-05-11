import json

# Function to extract usernames from JSON file
def extract_usernames(filename):
    with open(filename, 'r') as file:
        data = json.load(file)
        # Check if 'relationships_following' key exists
        if 'relationships_following' in data:
            # Extract usernames
            usernames = [entry['string_list_data'][0]['value'] for entry in data['relationships_following'] if 'string_list_data' in entry]
        else:
            # If 'relationships_following' key is not found, directly extract usernames
            usernames = [entry['string_list_data'][0]['value'] for entry in data if 'string_list_data' in entry]
    return usernames

# Extract usernames from followers.json and following.json
followers = extract_usernames('followers.json')
following = extract_usernames('following.json')

# Find users in following but not in followers
nonfollowers = [user for user in following if user not in followers]

# Print usernames in following but not in followers
print("Names not following you back")
for user in nonfollowers:
    print(user)

nonfollowers = [user for user in followers if user not in following]

print ("\nNames you don't follow back")
for user in nonfollowers:
    print(user)


