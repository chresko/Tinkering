#import <Foundation/Foundation.h>

#define PROMPTBLACK	@"Prisoner %d says black and %@"
#define PROMPTWHITE	@"Prisoner %d says white and %@"
#define BLACK		@"black"
#define WHITE		@"white"
#define LIVES		@"lives"
#define DIES		@"dies"

@interface Prisoner : NSObject

@property(nonatomic, retain) NSString* hatColor;
@property (nonatomic, assign) NSInteger blackHatCount;

-(id) initWithColor:(NSString*) color;

@end

@implementation Prisoner

@synthesize hatColor;
@synthesize blackHatCount;

-(id) init {
	if (self = [super init]) {
		self.hatColor = @"black";
		self.blackHatCount = 0;
	}
	
	return self;
}

-(id) initWithColor:(NSString*) color {
	if (self = [super init]) {
		self.hatColor = color;
		self.blackHatCount = 0;
	}
	
	return self;
}

-(void) dealloc {
	self.hatColor = nil;
	//[super dealloc];
}

@end

@interface PrisonerGame : NSObject {
	NSMutableArray* array;
	NSInteger numberOfPrisoners;
}

-(id) initWithNumberOfPrisoners:(NSInteger) prisoners;
-(void) start;

@end

@interface PrisonerGame()
-(void) helperPrint:(NSString*) prompt prisonerNumber:(NSInteger) number withPrisoner:(Prisoner*) p andColor:(NSString*) color;
@end
@implementation PrisonerGame

-(id) init {
	if (self = [super init]) {
		numberOfPrisoners = 0;
	}
	
	return self;
}

-(id) initWithNumberOfPrisoners:(NSInteger) prisoners {
	if (self = [super init]) {
		numberOfPrisoners = prisoners;
		array = [[NSMutableArray alloc] initWithCapacity:prisoners];
		
		for (int i = 0; i < numberOfPrisoners; ++i) {
			if (arc4random() % 2 == 0) {
				[array insertObject:[[Prisoner alloc] initWithColor:BLACK] atIndex:i];
			} else {
				[array insertObject:[[Prisoner alloc] initWithColor:WHITE] atIndex:i];
			}
		}
		
		NSInteger blackHats;	
		for (int i = 0; i < numberOfPrisoners-1; ++i) {
			blackHats = 0;
			for (int j = i+1; j < numberOfPrisoners; ++j) {
				if ([[[array objectAtIndex:j] hatColor] isEqualToString:BLACK]) {
					blackHats++;	// count of all black hats in front of me
				}
			}
			[[array objectAtIndex:i] setBlackHatCount:blackHats];
		}
	}
	
	return self;
}

-(void) helperPrint:(NSString*) prompt prisonerNumber:(NSInteger) number withPrisoner:(Prisoner*) p andColor:(NSString*) color {
	NSLog(prompt, number, ([p.hatColor isEqualToString:color] == YES) ? LIVES : DIES);
	NSLog(@"Actual color is %@\n", p.hatColor);
}

-(void) start {
	Prisoner* p = [array objectAtIndex:0];
	BOOL isEven = NO;
	NSInteger blackHatsRevealed = 0;
	if (p.blackHatCount % 2 == 0) {
		isEven = YES;
		[self helperPrint:PROMPTBLACK prisonerNumber:0 withPrisoner:p andColor:BLACK];
	} else {
		[self helperPrint:PROMPTWHITE prisonerNumber:0 withPrisoner:p andColor:WHITE];
	}
	
	NSInteger count;
	for (int i = 1; i < numberOfPrisoners; ++i) {
		p = [array objectAtIndex:i];
		count = blackHatsRevealed + p.blackHatCount; // number of black hats not including me
		if ((isEven && count % 2 != 0) || (!isEven && count % 2 == 0)) { // if even and odd in front of me or odd and even in front of me
			blackHatsRevealed++;
			[self helperPrint:PROMPTBLACK prisonerNumber:i withPrisoner:p andColor:BLACK];
		} else {
			[self helperPrint:PROMPTWHITE prisonerNumber:i withPrisoner:p andColor:WHITE];
		}
	}
}

-(void) dealloc {
	//[array release];
	//[super dealloc];
}

@end

int main(int argc, char *argv[]) {
	//NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];

	PrisonerGame* game = [[PrisonerGame alloc] initWithNumberOfPrisoners:101];
	[game start];
	//[game release];

	//[pool release];
	
	return 0;
}