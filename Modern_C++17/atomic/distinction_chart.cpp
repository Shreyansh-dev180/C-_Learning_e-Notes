//               THREADS
//                  │
//        ┌─────────┼─────────┐
//        ↓         ↓         ↓
//     mutex      atomic      cv
//        │         │         │
//        ↓         ↓         ↓
//  protect       safely     sleep/
//  shared        modify     wake
//  state         values     threads